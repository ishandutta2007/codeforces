#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

#define N 111111

struct cell {
    int t, w, num;
    
    bool operator <(const cell& A) const {
        return w < A.w;
    }
} a[N];
int n;
long long ans[N];
long long curm;

void doit(int l, int r) {
    curm = max(curm, (long long) a[r].t);
    sort(a + l, a + r + 1);
    
    long long pos = 0;
    for (int i = l; i <= r;) {
        int k = 1;
        while (i + k <= r && a[i + k].w == a[i].w) ++k;
        
        curm += a[i].w - pos;
        
        for (int j = 0; j < k; ++j) {
            ans[ a[i + j].num ] = curm;
        }
        
        curm += 1 + k / 2;
        pos = a[i].w;
        
        i += k;
    }
    
    curm += a[r].w;
}

int m;

int main() {
    //freopen("in", "r", stdin);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i].t, &a[i].w);
        a[i].num = i;
    }
    
    for (int i = 0; i < n; i += m) {
        int r = i + m - 1;
        if (r >= n) {
            doit(i, n - 1);
            break;
        }
        doit(i, r);
    }
    
    for (int i = 0; i < n; ++i) {
        printf("%I64d ", ans[i]);
        //cout << ans[i] << " ";
    }
    cout << endl;
        
    return 0;
}
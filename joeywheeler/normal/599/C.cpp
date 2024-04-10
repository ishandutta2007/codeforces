#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
int h[100005];
int c[100005];
int t[100005];
int r[100005];
int numn0;

void add(int i, int d) {
    if (r[i] == 0) numn0++;
    r[i] += d;
    if (r[i] == 0) numn0--;
}

int main() {
    scanf("%d", &n);
    FO(i,0,n) {
        scanf("%d", h+i); c[i] = h[i];
    }
    sort(c,c+n);
    int m = unique(c,c+n)-c;
    FO(i,0,n) {
        h[i] = lower_bound(c,c+m,h[i])-c;
    }
    FO(i,0,n) {
        c[i] = h[i];
    }
    sort(c,c+n);
    int ans = 0;
    FO(i,0,n) {
        add(c[i],1);
        add(h[i],-1);
        if (numn0 == 0) ans++;
    }
    printf("%d\n", ans);
}
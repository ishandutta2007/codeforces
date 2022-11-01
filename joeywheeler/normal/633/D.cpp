#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n;
int a[1005];
map<int,int> cnt;

int main() {
    scanf("%d", &n);
    FO(i,0,n) scanf("%d", a+i);
    sort(a,a+n);
    int ans = 2;
    FO(i,0,n) cnt[a[i]]++;
    ans = max(ans, cnt[0]);
    FO(i,0,n) FO(j,0,n) if (i != j) {
        int x = a[i], y = a[j];
        if (x == 0 && y == 0) continue;
        if (i && a[i] == a[i-1]) continue;
        int res = 2;
        map<int,int> mcnt;
        mcnt[x]++; mcnt[y]++;
        while (1) {
            int z = x+y;
            if (++mcnt[z] > cnt[z]) break;
            res++;
            x = y; y = z;
        }
        ans = max(ans,res);
    }
    printf("%d\n", ans);
}
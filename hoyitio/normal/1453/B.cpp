#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
const int maxn = 2e5 + 5;
ll a[maxn];
const ll inf = 1e16;
int main()
{
    int T; cin>>T;
    while(T--){
            ll ans = 0;
        ll mi = inf;
        int n; scanf("%d", &n);fors(i,1,n+1) {
            scanf("%lld", &a[i]);
            if(i > 1) ans += abs(a[i]-a[i-1]);
            }
        fors(i,1,n+1){
            ll pre = 0, now = 0;
            if(i-1 > 0) pre += abs(a[i]-a[i-1]);
            if(i+1 <=n) pre += abs(a[i+1]-a[i]);
            if(i-1>0&&i+1<=n) now = abs(a[i+1]-a[i-1]);
            mi = min(now-pre, mi);
        }
        ans += mi;
        printf("%lld\n", ans);
    }
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define fors(i,a,b) for(int i = (a); i < (b); ++i)
const int maxn = 2e5 +5 ;
ll a[maxn], b[maxn];
int n;
bool check(ll lim){
    ll res = 0;
    fors(i,1,n+1){
        if(a[i] <= lim) continue;
        else res += b[i];
    }
    return res <= lim;
}
int main(){
    int T; cin>>T;
    while(T--){
        scanf("%d", &n);
        fors(i,1,n+1) scanf("%lld", &a[i]);
        fors(i,1,n+1) scanf("%lld", &b[i]);
        ll l = 0, r = 1e9+7;
        ll ans = 0;
        while(l <= r){
            ll mid = (l+r)>>1;
            if(check(mid)) ans = mid, r = mid-1;
            else l = mid+1;
        }
        printf("%lld\n", ans);
    }
}
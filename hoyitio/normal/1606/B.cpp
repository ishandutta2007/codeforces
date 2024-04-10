#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fors(i,a,b) for(int i = (a); i < (b); ++i)
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define lowbit(x) (x&(-(x)))
using namespace std;
int main(){
    int T; cin>>T;
    while(T--){
        ll n, k; cin>>n>>k;
        ll cur = 1;
        ll res = n-1;
        ll ans = 0;
        while(res > 0 && cur <= k){
            ans++;
            ll d = min(cur, k);
            res -= d; cur += d;
        }
        if(res > 0){
            ans += (res+k-1)/k;
        }
        cout<<ans<<endl;
    }
    return 0;
}
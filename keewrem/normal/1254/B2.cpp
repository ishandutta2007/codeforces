#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
typedef vector<ll> v;
int n; v p; ll sus; ll N;
v kwk;
ll ans = 4000000000000000000;
int main(){
    cin >> N;
    p.resize(N);
    for(int i = 0; i < N; i++){scanf("%lld",&p[i]); sus+=p[i];}
    if(sus == 1){cout << -1; return 0;}
    for(ll i = 2; i*i <= sus; i++){
        if(sus%i==0)kwk.pb(i);
        while(sus%i==0)sus/=i;
    }
    if(sus>1)kwk.pb(sus);
    for(auto x: kwk){
        ll kek = 0, curr = 0;
        for(auto q: p){
            curr+=q%x; if(curr>x)curr-=x;
            kek+=min(curr,x-curr);
        }
        ans = min(kek,ans);
    }

    cout << ans << "\n";
    return 0;
}
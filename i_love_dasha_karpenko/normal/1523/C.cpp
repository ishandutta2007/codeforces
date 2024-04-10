//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'

void solve(){
    ll n;
    cin>>n;
    vector<ll> V;
    for(ll i = 1;i<=n;++i){
        ll x;
        cin>>x;
        if (x==1){
            for(ll to:V){
                cout<<to<<'.';
            }
            cout<<1<<endl;
            V.push_back(1);
        }
        else{
            while(!V.empty() && V.back()+1!=x)
                V.pop_back();
            for(ll i = 0;i+1<V.size();++i)
                cout<<V[i]<<'.';
            cout<<++V[V.size()-1]<<endl;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
        solve();
    
    return 0;
}
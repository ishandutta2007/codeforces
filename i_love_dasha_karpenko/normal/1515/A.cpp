//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 107;

ll A[DIM],vis[DIM];
void solve(){

    ll n,x;
    cin>>n>>x;

    for(ll i = 1;i<=n;++i){
        cin>>A[i];
        vis[i] = 0;
    }
    sort(A+1,A+1+n);
    ll sum = 0;
    vector<ll> ans;
    for(ll i = 1;i<=n;++i){
        if (sum+A[i]==x){
            continue;
        }
        else{
            vis[i] = 1;
            sum+=A[i];
            ans.push_back(A[i]);
        }
    }
    for(ll i = 1;i<=n;++i){
        if (vis[i])
            continue;
        sum+=A[i];
        if (sum==x){
            cout<<"NO\n";
            return;
        }
        ans.push_back(A[i]);
    }
    cout<<"YES\n";
    for(ll to:ans)
        cout<<to<<' ';
    cout<<endl;

} // l = x+1-A[i],r = x-1
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
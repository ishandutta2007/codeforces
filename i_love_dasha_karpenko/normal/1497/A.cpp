//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
const ll DIM = 1E3+7;
ll A[DIM];
void solve(){
    ll n;
    cin>>n;
    for(ll i = 1;i<=n;++i)
        cin>>A[i];
    ll ptr = 0;
    sort(A+1,A+1+n);

    vector<ll> V;
    for(ll i = 1;i<=n;++i){
        if (A[i]!=ptr){
            V.push_back(A[i]);
            continue;
        }
        else{
            cout<<A[i]<<' ';
            ++ptr;
        }
    }
    for(ll to:V)cout<<to<<' ';
    cout<<endl;

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
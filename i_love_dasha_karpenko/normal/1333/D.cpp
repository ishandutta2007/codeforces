#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long  ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> multi_set;
#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 3000+7;
const ll INF = 1e18;
ll A[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,k;
    cin>>n>>k;
    forn(i,n){
        char ch;
        cin>>ch;
        if (ch=='R')A[i] = 1;
    }
    vector<vector<ll> > ans;
    ll cnt = 0;
    while(1){
        vector<ll> V;
        forn(i,n-1){
            if (A[i]==1 && A[i+1]==0)V.pb(i);
        }
        for(ll to:V){
            A[to] = 0;
            A[to+1] = 1;
        }
        if (V.empty())break;
        cnt+=V.size();
        ans.pb(V);
    }
    if (k<ans.size()){
        cout<<"-1\n";
        return 0;
    }
    if (k<=cnt){
        for(ll i = 0;i<ans.size();i++){
            ll j = 0;
            for(j = 0;j<ans[i].size();++j){
                if (k==ans.size()-i){
                    break;
                }
                cout<<"1 "<<ans[i][j]<<endl;
                k--;
            }
            if (k==ans.size()-i){
                if (j!=ans[i].size())k--;
                else continue;
                cout<<ans[i].size()-j<<' ';
                while(j<ans[i].size())cout<<ans[i][j++]<<' ';
                cout<<endl;

            }
        }
        return 0;
    }
    cout<<"-1\n";

    return 0;
}
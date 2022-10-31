#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
const ll DIM = 507;
const ll INF = 10000000007;
const ll MOD = ll(1000000007) ;
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define fi first
#define sc second
#define x1 Artem
#define y1 Pidor
const ll LOG = 9;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> my_super_set;

ll t;
int main()
{
    //freopen("input.txt","r",stdin);
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>t;
    forn(query,t){
        ll r1 = 0,r2= 0,r3= 0;
        ll n;cin>>n;
        ll a,b,c; cin>>a>>b>>c;
        vector<ll> v1,v2,v3;
        forn(i,n){
            char ch; cin>>ch;
            if (ch=='R'){
                    r1++;
            v1.pb(i);
            }
            else if (ch=='P'){r2++;v2.pb(i);}
            else {r3++;v3.pb(i);}
        }
        ll res=min(a,r3)+min(b,r1)+min(c,r2);
        //cout<<res<<endl;

        if (res*2>=n){
            cout<<"YES\n";
            vector<char> V;
            vector<ll> vis;
            vis.resize(n+3);
            V.resize(n+3);
            for(ll i = 0;i<min(a,r3);i++){
                V[v3[i]-1] = 'R';
                vis[v3[i]-1] = 1;
            }
            for(ll i = 0;i<min(b,r1);i++){
                V[v1[i]-1] = 'P';
                vis[v1[i]-1] = 1;
            }
            for(ll i = 0;i<min(c,r2);i++){
                V[v2[i]-1] = 'S';
                vis[v2[i]-1] = 1;
            }
            a-=min(a,r3);
        b-=min(b,r1);
        c-=min(c,r2);
            for(ll i = 0;i<n;i++){
                if (vis[i]==0){
                       // cout<<1;
                    if (a!=0){
                        a--;
                        cout<<'R';
                    }
                    else if (b!=0){
                        b--;
                        cout<<'P';
                    }
                    else{
                        c--;
                        cout<<'S';
                    }
                }
                else cout<<V[i];
            }
            cout<<endl;
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}
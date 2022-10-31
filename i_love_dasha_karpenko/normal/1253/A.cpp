#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1ll;i<=n;++i)
#define pb push_back
#define endl '\n'
#define po(x) (1ll<<x)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<pp,null_type,less<pp>,rb_tree_tag,tree_order_statistics_node_update> satan_set;
const ll DIM = 100000 +7;
const ll INF = 10E17+7;
ll A[DIM],B[DIM];
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin>>t;
    forn(q,t){
        ll n; cin>>n;
        forn(i,n)cin>>A[i];
        forn(i,n)cin>>B[i];
        ll l=-1,r=-1,flag = 0;
        forn(i,n){
            if (A[i]!=B[i] && l!=-1 && r!=i-1){
                flag = 1;
                break;
            }
            else if (A[i]!=B[i]){
                if (l==-1)r = l = i;
                else {
                    r++;
                }
            }
        }

        if (l!=-1){
            ll dif = A[l]-B[l];

            for(ll i = l+1;i<=r;i++){
                if (A[i]-B[i]!=dif){
                    flag = 1;
                    break;
                }
            }
            if (dif>0)flag = 1;
        }
        if (flag==1 )cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}

// 1 2 3
//
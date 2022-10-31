#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 2*10E4+7;
const ll INF = 10E17;

ll A[DIM],ans[DIM];
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll te;
    cin>>te;
    while(te--){
        ll n;
        cin>>n;
        forn(i,n-1){
            char ch;
            cin>>ch;
            A[i] = 0;
            if (ch=='<')A[i] = 1;
        }
        deque<ll> Q;
        forn(i,n)Q.pb(i);
        forn(i,n){
            ll cnt = 0;
            ll p = i;
            while(A[p]==1 && p<n){
                cnt++;
                p++;
            }
            cnt = p;
            while(p>=i){
                ans[p] = Q.back();
                Q.pop_back();
                p--;
            }
            i = cnt;
        }
        forn(i,n)cout<<ans[i]<<' ';
        cout<<endl;

        forn(i,n)Q.pb(i);
        forn(i,n){
            ll cnt = 0;
            ll p = i;
            while(A[p]==0 && p<n){
                cnt++;
                p++;
            }
            cnt = p;
            while(p>=i){
                ans[p] = Q.front();
                Q.pop_front();
                p--;
            }
            i = cnt;
        }
        forn(i,n)cout<<ans[i]<<' ';
        cout<<endl;
    }
    return 0;
}
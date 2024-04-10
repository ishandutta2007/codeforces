#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 500+7;
const ll INF = 1E16;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}

ll A[DIM],B[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        forn(i,n)cin>>A[i];
        forn(i,n)cin>>B[i];
        ll flag = 0;
        forn(i,n-1){
            if (A[i]>A[i+1]){
                flag = 1;
                break;
            }
        }
        if (flag==0){
            cout<<"Yes\n";
            continue;
        }
        flag = 0;
        forn(i,n)if (B[i]!=B[1])flag = 1;
        if (flag)cout<<"Yes\n";
        else cout<<"No\n";
    }

    return 0;
}
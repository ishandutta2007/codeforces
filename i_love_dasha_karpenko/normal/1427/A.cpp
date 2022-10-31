#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

typedef long double ld;
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
#define log sdfdsfdsf

const ll DIM = 500+7;

const ll MOD = 1e9+7;

const ll INF = 1E19+70;
const ld eps = 0.00000000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution <int> (a, b)(rng);
}

ll A[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll s = 0;
        forn(i,n){
            cin>>A[i];
            s+=A[i];
        }
        if (s>0)
        sort(A+1,A+1+n,greater<ll>());
        else sort(A+1,A+1+n);
        ll flag = 0,sum = 0;
        forn(i,n){
            sum+=A[i];
            if (sum==0){
                flag = 1;
                break;
            }
        }
        if (flag==0){
            cout<<"YES\n";
            forn(i,n)
            cout<<A[i]<<' ';
            cout<<endl;
        }
        else{
            cout<<"NO\n";
        }
    }

    return 0;

}
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

const ll DIM = 3E5  +7;

const ll MOD = 1e9+7;

const ll INF = 1E18+70;
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
        for(ll i =0;i<n;++i){
            char ch;
            cin>>ch;
            if (ch=='>')A[i] = 1;
            else if (ch=='<')A[i] = 2;
            else A[i] = 3;
        }
        ll flag = 0;
        ll f = 0;
        for(ll i = 0;i<n;++i){
            if (A[i]!=1 && A[i]!=3){
                f = 1;
                break;
            }
        }
        flag = max(flag,1-f);
        f = 0;
        for(ll i = 0;i<n;++i){
            if (A[i]!=2 && A[i]!=3){
                f = 1;
                break;
            }
        }
        flag = max(flag,1-f);
        ll res = 0;
        for(ll i =0;i<n;++i){
            if (A[i]==3 || A[(i-1+n)%n]==3)++res;
        }
        if (flag)res = n;
        cout<<res<<endl;
    }
    return 0;
}
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

const ll DIM = 2E5+7;

const ll MOD = 1e9+7;

const ll INF = 1E16+7;
const ld eps = 0.00000000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution <int> (a, b)(rng);
}
ll A[DIM],B[DIM],C[DIM],ans[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        forn(i,n)cin>>A[i];
        forn(i,n)cin>>B[i];
        forn(i,n)cin>>C[i];
        ll last = 0;
        A[0] = INF;
        forn(i,n){
            if (i==1){
                ans[1] = A[1];
                cout<<A[1]<<' ';
                continue;
            }
            if (i==n){
                if (A[i]!=ans[i-1] && A[i]!=ans[1]){
                    cout<<A[i]<<' ';
                    ans[i] = A[i];
                    continue;
                }
                else if (B[i]!=ans[i-1] && B[i]!=ans[1]){
                    cout<<B[i]<<' ';
                    ans[i] = B[i];

                }
                else if (C[i]!=ans[i-1] && C[i]!=ans[1]){
                    cout<<C[i]<<' ';
                    ans[i] = C[i];
                }
            }
            else{
                ll tmp = ans[1];
                if (i!=2)
                ans[1] = INF;
                if (A[i]!=ans[i-1] && A[i]!=ans[1]){
                    cout<<A[i]<<' ';
                    ans[i] = A[i];
                }
                else if (B[i]!=ans[i-1] && B[i]!=ans[1]){
                    cout<<B[i]<<' ';
                    ans[i] = B[i];
                }
                else if (C[i]!=ans[i-1] && C[i]!=ans[1]){
                    cout<<C[i]<<' ';
                    ans[i] = C[i];
                }
                ans[1] = tmp;
            }

        }
        cout<<endl;
    }
    return 0;
}
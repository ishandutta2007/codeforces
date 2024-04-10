#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long  ll;
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
#define log sdfdsfdsf

const ll DIM = 2E5+7;
const ll DIM2 = 1E6+7;
const ll INF = 2E9+140;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
const ll masksz = po(11)-1;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}


ll n,A[DIM],P[DIM],mx[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    set<pp> S;
    forn(i,n){
        S.insert({i,i});
        mx[i] = i;
    }
    map<ll,ll> M;
    forn(i,n-1){
        cin>>A[n-i];
        M[A[n-i]]++;
        S.erase({A[n-i],A[n-i]});
    }
    forn(i,n-1){
        if (S.empty()){
            cout<<"-1\n";
            return 0;
        }
        pp v = *S.begin();
        S.erase(S.begin());
        P[v.sc] = A[i];
        mx[A[i]] = max(mx[A[i]],v.fi);
        M[A[i]]--;
        if (M[A[i]]==0)
            S.insert({mx[A[i]],A[i]});
    }
    cout<<A[n-1]<<endl;
    forn(i,n){
        if (P[i]==0)continue;
        cout<<i<<' '<<P[i]<<endl;;
    }

    return 0;
}
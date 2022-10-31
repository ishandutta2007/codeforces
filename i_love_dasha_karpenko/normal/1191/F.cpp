#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define DIM 200007
#define DIM2 DIM*DIM
#define DIM3 200007
#define INF 10E10
#define MAXN 2750137
#define LG 18
#define MODULO 998244353
#define fi first
#define sc second
#define pb push_back
#define pu push
#define sz size()
#define po(power) ( 1<<power)
#define schnell ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"

typedef long long ll;
typedef long double ld;
const ld eps = 0.00000001;
const ll MASK(1 << 10);
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef ll msk[MASK + 7];
typedef vector<ll> vec;
typedef pair<string, string> ps;
#define forn(i,n) for (ll i = 1;i<=n;i++)
#define fore(y,i,n) for (ll i = y;i<=n;i++)
typedef tree<
int, //    
null_type, // null_type.     TYPE2     map<int,TYPE2>
less<int>, // 
rb_tree_tag, //   - 
tree_order_statistics_node_update> //' ;)
my_super_set; //    



my_super_set S;

ll n;
pll A[DIM];
set<ll> X;
bool mc(pll a, pll b) {
    if (a.sc==b.sc)return a.fi<b.fi;
	return a.sc > b.sc;
}
int main()
{
	schnell;
	cin >> n;
	forn(i, n)cin >> A[i].fi >> A[i].sc;
	sort(A + 1, A + 1 + n,mc);
	ll res = 0,prevl = 0;
	forn(i, n) {
        S.insert(A[i].fi);

        ll l = S.order_of_key(A[i].fi)+1;
        ll r = S.size()-l+1;
        if (A[i].sc==A[i-1].sc){
            res+=(l-prevl)*r;
            if (X.count(A[i].fi)==0)res+=prevl;
        }
        else{
            res+=l*r;
        }
        prevl=l;
        X.insert(A[i].fi);
        //cout<<res<<endl;
        //cout<<l<<' '<<r<<endl;
	}
	cout<<res<<endl;
}
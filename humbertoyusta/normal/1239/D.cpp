    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba                    */
#include<bits/stdc++.h>
using namespace std;
/// Pragmas
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03") // Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero=upper") // Enable AVX
//#pragma GCC target("avx2") // Enable AVX
//#pragma comment(linker, "/STACK:1024000000,1024000000") // Increase stack limit
//#pragma GCC target("sse,sse2,sse,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") // I don't know what it is
/// Macros:
#define int long long
#define f first
#define s second
#define db(x) cerr << #x << ": " << (x) << '\n';
#define pb push_back
#define all(x) x.begin() , x.end()
#define rall(x) x.rbegin() , x.rend()
typedef pair<int,int> ii;
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
/// Constraints:
const int maxn = 1000010;
const int mod = 1000000007;
const int mod2 = 998244353;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = 1ll * mod * mod;
const ld pi = acos(-1);
/// Prime Numbers:
// 2, 173, 179, 181, 197, 311, 331, 737, 1009, 2011, 2027, 3079, 4001, 10037, 10079, 20011, 20089;
// 100003, 100019, 100043, 200003, 200017, 1000003, 1000033, 1000037, 1000081;
// 2000003, 2000029, 2000039, 1000000007, 1000000021, 2000000099;
/// Red-Black Tree Template ---------------------------------
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update > ordered_set;
/// Quick Functions------------------------------------------
int qpow(int b,int e){
    if( !e ) return 1;
    if( e & 1 ) return qpow(b,e-1) * b % mod;
    int pwur = qpow(b,e>>1);
    return pwur * pwur % mod;
}
int modinv(int x){ return qpow(x,mod-2); }
bool isprime(int x){
    for(int i=2; i*i<=x; i++)
        if( x % i == 0 )
            return false;
    return true;
}
mt19937_64 r(time(0));
int rng (int a, int b){
    return uniform_int_distribution<int>(a,b)(r);
}
/// My Code -------------------------------------------------

/***
	Two-Sat

	Complexity: O(n)

	Tested: POI (Gates)
*/

struct satisfiability_twosat
{
	int n;
	vector<vector<int>> imp;

	satisfiability_twosat(int n) : n(n), imp(2 * n) {}

	void add_edge(int u, int v)
	{
		imp[u].push_back(v);
	}

	int neg(int u) { return (n << 1) - u - 1; }

	void implication(int u, int v)
	{
		add_edge(u, v);
		add_edge(neg(v), neg(u));
	}

	vector<bool> solve(bool flag)
	{
		int size = 2 * n;
		vector<int> S, B, I(size);

		for(int i=0; i<2*n; i++){
            sort(all(imp[i]));
            if( flag )
                reverse(all(imp[i]));
        }

		function<void(int)> dfs = [&](int u)
		{
			B.push_back(I[u] = S.size());
			S.push_back(u);

			for (int v : imp[u])
				if (!I[v]) dfs(v);
				else while (I[v] < B.back()) B.pop_back();

			if (I[u] == B.back())
				for (B.pop_back(), ++size; I[u] < S.size(); S.pop_back())
					I[S.back()] = size;
		};

		if( flag == 0 ){
            for (int u = 0; u < 2 * n; ++u)
                if (!I[u]) dfs(u);
        }
        else{
            for (int u = 2*n-1; u >= 0; u--)
                if (!I[u]) dfs(u);
        }

		vector<bool> values(n);

		for (int u = 0; u < n; ++u)
			if (I[u] == I[neg(u)]) return {};
			else values[u] = I[u] < I[neg(u)];

		return values;
	}
};


int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc;
    //tc = 1;
    cin >> tc;
    while( tc-- ){
        int n, m;
        cin >> n >> m;
        satisfiability_twosat sat1(n), sat2(n);
        for(int i=1; i<=m; i++){
            int u, v;
            cin >> u >> v;
            u--, v--;
            if( u == v ) continue;
            sat1.implication(u,v);
            sat2.implication(u,v);
        }

        /// sat 1 min
        sat1.implication(0,sat1.neg(0));
        vector<bool> ans = sat1.solve(0);

        bool good = 0;
        for(int i=0; i<(int)ans.size()-1; i++)
            if( ans[i] != ans[i+1] )
                good = 1;

        if( good ){
            cout << "YES\n";
            vector<int> v1, v2;
            for(int i=0; i<n; i++)
                if( ans[i] == 0 ) v1.pb(i);
                    else v2.pb(i);
            cout << v2.size() << ' ' << v1.size() << '\n';
            for( auto i : v2 ) cout << i + 1 << ' '; cout << '\n';
            for( auto i : v1 ) cout << i + 1 << ' '; cout << '\n';
            continue;
        }

        /// sat 1 max
        ans = sat1.solve(1);

        good = 0;
        for(int i=0; i<(int)ans.size()-1; i++)
            if( ans[i] != ans[i+1] )
                good = 1;

        if( good ){
            cout << "YES\n";
            vector<int> v1, v2;
            for(int i=0; i<n; i++)
                if( ans[i] == 0 ) v1.pb(i);
                    else v2.pb(i);
            cout << v2.size() << ' ' << v1.size() << '\n';
            for( auto i : v2 ) cout << i + 1 << ' '; cout << '\n';
            for( auto i : v1 ) cout << i + 1 << ' '; cout << '\n';
            continue;
        }

        /// sat 2 min
        sat2.implication(sat2.neg(0),0);
        ans = sat2.solve(0);

        good = 0;
        for(int i=0; i<(int)ans.size()-1; i++)
            if( ans[i] != ans[i+1] )
                good = 1;

        if( good ){
            cout << "YES\n";
            vector<int> v1, v2;
            for(int i=0; i<n; i++)
                if( ans[i] == 0 ) v1.pb(i);
                    else v2.pb(i);
            cout << v2.size() << ' ' << v1.size() << '\n';
            for( auto i : v2 ) cout << i + 1 << ' '; cout << '\n';
            for( auto i : v1 ) cout << i + 1 << ' '; cout << '\n';
            continue;
        }

        /// sat 2 max
        ans = sat2.solve(1);

        good = 0;
        for(int i=0; i<(int)ans.size()-1; i++)
            if( ans[i] != ans[i+1] )
                good = 1;

        if( good ){
            cout << "YES\n";
            vector<int> v1, v2;
            for(int i=0; i<n; i++)
                if( ans[i] == 0 ) v1.pb(i);
                    else v2.pb(i);
            cout << v2.size() << ' ' << v1.size() << '\n';
            for( auto i : v2 ) cout << i + 1 << ' '; cout << '\n';
            for( auto i : v1 ) cout << i + 1 << ' '; cout << '\n';
            continue;
        }

        cout << "NO\n";
    }

    return 0;
}
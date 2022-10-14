#include<bits/stdc++.h>
using namespace std;
// Pragma
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03")
// Macros:
#define f first
#define s second
typedef long long ll;
// debugging macros
#define db(x) cerr << #x << ": " << (x) << '\n';
#define db_v(x) cerr << #x << ": ["; for( auto i : (x) ) cerr << i << ", "; cerr << "]\n";
#define db_p(x) cerr << #x << ": " << (x).first << " " << (x).second << '\n';
// Constraints:
const int maxn = 1000010;
const int mod = 1000000007;
const int mod2 = 998244353;
const ll INF = 1ll * mod * mod;
const double eps = 1e-9;
// Quick Functions------------------------------------------
ll qpow(ll b,int e){
    if( !e ) return 1;
    if( e & 1 ) return qpow(b,e-1) * b % mod;
    ll pwur = qpow(b,e>>1);
    return pwur * pwur % mod;
}
mt19937_64 rnd(time(0));
ll rng (ll a, ll b){
    return uniform_int_distribution<ll>(a,b)(rnd);
}
// Problem starts here

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

	vector<bool> solve()
	{
		int size = 2 * n;
		vector<int> S, B, I(size);

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

		for (int u = 0; u < 2 * n; ++u)
			if (!I[u]) dfs(u);

		vector<bool> values(n);

		for (int u = 0; u < n; ++u)
			if (I[u] == I[neg(u)]) return {};
			else values[u] = I[u] < I[neg(u)];

		return values;
	}
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc;
    //tc = 1;
    cin >> tc;
    while( tc-- ){
        int n, m;
        cin >> n >> m;

        vector<pair<int,int>> g[n];
        for(int i=0; i<n-1; i++){
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }

        satisfiability_twosat twosat(n);
        function<void(int,int,int)> dfs = [&](int u,int p,int w){
                    if( u != p && w >= 0 ){
                        int a = u, b = p;
                        if( __builtin_popcount(w) % 2 == 0 ){
                            twosat.implication(a,b);
                            twosat.implication(b,a);
                            twosat.implication(twosat.neg(a),twosat.neg(b));
                            twosat.implication(twosat.neg(b),twosat.neg(a));
                        }
                        else{
                            twosat.implication(a,twosat.neg(b));
                            twosat.implication(b,twosat.neg(a));
                            twosat.implication(twosat.neg(a),b);
                            twosat.implication(twosat.neg(b),a);
                        }
                    }
            for( auto v : g[u] ){
                if( v.f != p ){
                    dfs(v.f,u,v.s);
                }
            }
        };
        dfs(0,0,0);

        for(int i=0; i<m; i++){
            int a, b, p;
            cin >> a >> b >> p;
            a--, b--;
            if( p == 0 ){
                            twosat.implication(a,b);
                            twosat.implication(b,a);
                            twosat.implication(twosat.neg(a),twosat.neg(b));
                            twosat.implication(twosat.neg(b),twosat.neg(a));
            }
            else{
                            twosat.implication(a,twosat.neg(b));
                            twosat.implication(b,twosat.neg(a));
                            twosat.implication(twosat.neg(a),b);
                            twosat.implication(twosat.neg(b),a);
            }
        }

        vector<bool> ans = twosat.solve();
        if( ans.empty() ){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
            function<void(int,int,int)> dfs = [&](int u,int p,int w){
                if( u != p && w >= 0 )
                    cout << p + 1 << ' ' << u + 1 << ' ' << w << '\n';
                if( u != p && w == -1 )
                    cout << p + 1 << ' ' << u + 1 << ' ' << ( ans[u] ^ ans[p] ) << '\n';
                for( auto v : g[u] ){
                    if( v.f != p ){
                        dfs(v.f,u,v.s);
                    }
                }
            };
            dfs(0,0,0);
        }
    }

    return 0;
}
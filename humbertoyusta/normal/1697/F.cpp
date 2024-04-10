#include<bits/stdc++.h>
using namespace std;
// Pragma
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03")
// Macros:
#define f first
#define s second
typedef long double ld;
typedef long long ll;
// debugging macros
#define db(x) cerr << #x << ": " << (x) << '\n';
#define db_v(x) cerr << #x << ": ["; for( auto i : (x) ) cerr << i << ", "; cerr << "]\n";
#define db_p(x) cerr << #x << ": " << (x).first << " " << (x).second << '\n';
// Constraints:
const int maxn = 1000010;
const int mod = 1000000007;
const ll INF = 1ll * mod * mod;
const int mod2 = 998244353;
const double eps = 1e-9;
// Quick Functions------------------------------------------
ll qpow(ll b,int e){
    if( !e ) return 1;
    if( e & 1 ) return qpow(b,e-1) * b % mod;
    int pwur = qpow(b,e>>1);
    return pwur * pwur % mod;
}
mt19937_64 rnd(time(0));
ll rng (ll a, ll b){
    return uniform_int_distribution<ll>(a,b)(rnd);
}
// Problem starts here

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
    cout.setf(ios::fixed); cout.precision(12);
    srand(time(0));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        int N, M, K;
        cin >> N >> M >> K;

        satisfiability_twosat twosat(N*(K+1));

        for (int i=0; i<N; i++)
        {
            twosat.implication(twosat.neg(i*(K+1)+0), i*(K+1)+0);
            twosat.implication(i*(K+1)+K, twosat.neg(i*(K+1)+K));
            for(int j=0; j<=K; j++)
            {
                if (j < K)
                    twosat.implication((i*(K+1)+(j+1)), (i*(K+1)+j));
                if (i + 1 < N)
                    twosat.implication(i*(K+1)+j, (i+1)*(K+1)+j);
            }
        }

        for (int i=0; i<M; i++)
        {
            int typ;
            cin >> typ;
            if (typ == 1)
            {
                int u, x;
                cin >> u >> x;
                u --, x --;
                twosat.implication((u*(K+1)+(x)), (u*(K+1)+(x+1)));
            }
            if (typ == 2)
            {
                int u, v, s;
                cin >> u >> v >> s;
                u --, v --, s -= 2;
                for (int a=0; a<=K; a++)
                    for (int b=0; b<=K; b++)
                        if (a + b > s)
                        {
                            twosat.implication(u*(K+1)+a, twosat.neg(v*(K+1)+b));
                        }
                        else
                        {
                            ;//twosat.implication(twosat.neg(v*(K+1)+b), u*(K+1)+a);
                        }
            }
            if (typ == 3)
            {
                int u, v, s;
                cin >> u >> v >> s;
                u --, v --, s -= 2;
                for (int a=0; a<=K; a++)
                    for (int b=0; b<=K; b++)
                        if (a + b - 2 < s)
                        {
                            twosat.implication(twosat.neg(v*(K+1)+b), u*(K+1)+a);
                        }
                        else
                        {
                            ;//twosat.implication(u*(K+1)+a, twosat.neg(v*(K+1)+b));
                        }
            }
        }

        vector<bool> ans = twosat.solve();
        if (ans.empty())
        {
            cout << -1 << '\n';
        }
        else{
            vector<int> res(N, -1);
            for (int i=0; i<N; i++)
                for (int j=0; j<=K; j++)
                    if (ans[i*(K+1)+j])
                        res[i] = j;

            for (int i=0; i<N; i++)
            {
                cout << res[i] + 1 << " \n"[i+1==N];
            }
        }
    }


    return 0;
}
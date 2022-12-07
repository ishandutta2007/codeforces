#include <bits/stdc++.h>
#ifdef LOCAL
#include "template.h"
#endif

using namespace std;
#ifndef LOCAL
#define dbg(...) (void)0
#define ARR(arr, ...) (void)0
#define eprintf(...) (void)0
#endif

#define mp make_pair
#define rand govno_ebanoe
#define dbg_time() eprintf("\n\nTime: %.3lf\n", double(clock()) / CLOCKS_PER_SEC)

using ll = long long;
using pii = pair<int, int>;
using dbl = double;

const int N = 1010;
int n;
vector<int> go[N];
vector<int> vs1, vs2;

vector<int> readV() {
    int sz;
    cin >> sz;
    vector<int> res(sz);
    for(auto& x : res) {
        cin >> x;
        --x;
    }
    return res;
}

int ask1(int v) {
    cout << "A " << v + 1 << endl;
    int u;
    cin >> u;
    --u;
    return u;
}

int ask2(int v) {
    cout << "B " << v + 1 << endl;
    int u;
    cin >> u;
    --u;
    return u;
}

int hs[N];

void dfs(int v, int p) {
    for(auto u : go[v]) {
        if (u == p)
            continue;
        hs[u] = hs[v] + 1;
        dfs(u, v);
    }
}

void solve1() {
    cin >> n;
    for(int i = 0; i < n; ++i) {
        go[i].clear();
    }
    for(int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        go[a].push_back(b);
        go[b].push_back(a);
    }
    vs1 = readV();
    vs2 = readV();
    auto r = ask2(vs2[0]);
    hs[r] = 0;
    dfs(r, -1);
    int best = vs1[0];
    for(auto x : vs1)
        if (hs[x] < hs[best])
            best = x;
    auto y = ask1(best);
    if (find(vs2.begin(), vs2.end(), y) == vs2.end()) {
        cout << "C " << -1 << endl;
    } else {
        cout << "C " << best + 1 << endl;
    }
}

void solve()
{
    int T;
    cin >> T;
    while(T--)
        solve1();
}

#ifdef LOCAL
#define ERR_CATCH
//#define NOERR
#endif

int main()
{
#ifdef LOCAL
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#ifdef NOERR
	freopen("err.txt", "w", stderr);
#endif
#else
	//freopen("sum.in", "r", stdin);
	//freopen("sum.out", "w", stdout);
#endif

#ifdef ERR_CATCH
	try
	{
#endif

#ifdef ST
		ios_base::sync_with_stdio(false);
		while (true)
			solve();
#endif

#ifdef CASES
#define MULTITEST
#endif

#ifdef MULTITEST
		int t;
		scanf("%d", &t);
		char endl1[5];
		fgets(endl1, 5, stdin);
		for (int i = 0; i < t; ++i)
		{
#ifdef CASES
			printf("Case #%d: ", i + 1);
#endif
			solve();
#ifdef CASES
			eprintf("Passed case #%d:\n", i + 1);
#endif
		}
#else
		solve();
#endif

#ifdef ERR_CATCH
	}
	catch (logic_error e)
	{
		dbg(e.what());
		puts("___________________________________________________________________________");
		exit(0);
	}
#endif
	dbg_time();
}
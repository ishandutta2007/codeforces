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
using uint = unsigned int;

const int N = 4e5 + 10;
unordered_map<uint, int> codes;

int get(uint x) {
    auto it = codes.find(x);
    if (it == codes.end()) {
        auto id = codes.size();
        codes[x] = id;
        return id;
    }
    return it->second;
}

struct DSU {
    int rank[N];
    int dsu[N];
    int x[N];

    DSU() : rank(), x() {
        iota(dsu, dsu + N, 0);
    }

    pii get(int v) {
        int cur = 0;
        while(dsu[v] != v) {
            cur ^= x[v];
            v = dsu[v];
        }
        return {v, cur};
    }

    bool unite(int a, int b, int cx) {
        auto pa = get(a);
        auto pb = get(b);
        if (pa.first == pb.first)
            return false;
        a = pa.first;
        b = pb.first;
        cx ^= pa.second ^ pb.second;
        if (rank[a] == rank[b])
            ++rank[a];
        if (rank[a] < rank[b])
            swap(a, b);
        dsu[b] = a;
        x[b] = cx;
        return true;
    }
} dsu;

void solve() {
    int q;
    scanf("%d", &q);
    uint last = 0;
    while(q--) {
        uint l, r, x;
        int t;
        scanf("%d%u%u", &t, &l, &r);
        l ^= last;
        r ^= last;
        if (l > r)
            swap(l, r);
        ++r;
        l = get(l);
        r = get(r);
        if (t == 1) {
            scanf("%u", &x);
            x ^= last;
            dsu.unite(l, r, x);
        } else {
            auto pa = dsu.get(l);
            auto pb = dsu.get(r);
            if (pa.first != pb.first) {
                last = 1;
                puts("-1");
            } else {
                last = pa.second ^ pb.second;
                printf("%u\n", last);
            }
        }
    }
}

#ifdef LOCAL
#define ERR_CATCH
//#define NOERR
#endif

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
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
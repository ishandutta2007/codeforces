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
using pll= pair<ll, ll>;
using dbl = double;


const int P = 1e9 + 7;
int sum(int a, int b) {
    a += b;
    return a >= P ? a - P : a;
}
int sub(int a, int b) {
    return sum(a, P - b);
}
int mul(int a, int b) {
    return (ll) a * b % P;
}
int bpow(int a, int pw) {
    int res = 1;
    for(; pw > 0; pw /= 2, a = mul(a, a))
        if (pw % 2 == 1)
            res = mul(res, a);
    return res;
}
int inv(int x) {
    return bpow(x, P - 2);
}

const int N = 100;
int cp[N];
int fp[N];
int invs[N];

int solve(int p, int pw, int k) {
    dbg(p, pw);
    fill(cp, cp + pw + 1, 0);
    cp[pw] = 1;
    for(int i = 0; i <= pw + 1; ++i)
        invs[i] = inv(i);
    for(int id = 0; id < k; ++id) {
        fill(fp, fp + pw + 1, 0);
        for(int j = 0; j <= pw; ++j) {
            auto add = mul(cp[j], invs[j + 1]);
            for(int x = 0; x <= j; ++x) {
                fp[x] = sum(fp[x], add);
            }
        }
        copy(fp, fp + pw + 1, cp);
    }
    int res = 0;
    int cur = 1;
    dbg(ARR(cp, pw + 1));
    for(int i = 0; i <= pw; ++i) {
        res = sum(res, mul(cur, cp[i]));
        cur = mul(cur, p);
    }
    return res;
}

void solve()
{
    ll n;
    int k;
    cin >> n >> k;
    vector<pll> divs;
    ll x = 2;
    for(; x * x < n; ++x) {
        if (n % x != 0) {
            continue;
        }
        divs.emplace_back(x, 0);
        while(n % x == 0) {
            n /= x;
            ++divs.back().second;
        }
    }
    dbg(x, n);
    if (x * x == n) {
        divs.emplace_back(x, 2);
    } else if(n != 1) {
        divs.emplace_back(n, 1);
    }
    dbg(divs);
    int ans = 1;
    dbg("ME");
    for(auto pd : divs) {
        ll p;
        ll pw;
        tie(p, pw) = pd;
        ans = mul(ans, solve(p % P, pw, k));
    }
    cout << ans << endl;
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
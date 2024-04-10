#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

const ld eps = 1e-8;

ll k;
ld Dx = sqrt(3) / 2;

inline bool covers(int y, int x)
{
	ld x1 = 2 * Dx * x + Dx * y;
	ld x2 = x1 + Dx;
	ld y2 = y * 1.5 + 0.5;
	ld y1 = y2 + 0.5;
	//cout << x << ' ' << y << ' ' << x1 << ' ' << x2 
	return x1 * x1 + y1 * y1 <= k * k + eps && x2 * x2 + y2 * y2 <= k * k + eps;
}

int main()
{
	cin >> k;
	ll answer = 0;
	for (int dy = 0; ; dy++)
	{
		int l = 0;
		int r = 2 * k;
		while (r - l > 1)
		{
			int m = (l + r) / 2;
			if (covers(dy, m)) l = m;
			else r = m;
		}
		//cout << dy << ' ' << l << endl;
		if (l == 0) break;
		answer += l;
	}
	answer *= 6;
	answer += 1;
	cout << answer << endl;
    return 0;
}
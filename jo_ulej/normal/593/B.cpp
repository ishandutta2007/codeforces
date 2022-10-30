#include <bits/stdc++.h>
 
#define INT_INF (2 * 1e9)
#define LL_INF  (2LL * 1e18)
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef __LOCAL
#define DBG(X) cout << #X << "=" << (X) << endl;
#else
#define DBG(X)
#endif
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll mod = 1e7 + 9;

struct Line
{
	ll k, b, val1, val2;
};

bool my_cmp(Line a, Line b)
{
	if(a.val1 == b.val1)
		return a.val2 < b.val2;

	return a.val1 < b.val1;
}

void solve()
{
	int n;
	ll x1, x2;
	vector<Line> lines;

	cin >> n >> x1 >> x2;
	lines.resize(n);

	for(int i = 0; i < n; ++i)
	{
		cin >> lines[i].k >> lines[i].b;

		lines[i].val1 = lines[i].k * x1 + lines[i].b;
		lines[i].val2 = lines[i].k * x2 + lines[i].b;
	}

	sort(lines.begin(), lines.end(), my_cmp);

	for(int i = 0; i + 1 < n; ++ i)
	{
		if(lines[i].val1 < lines[i + 1].val1 && lines[i].val2 > lines[i + 1].val2)
		{
			cout << "YES" << endl;

			return;
		}
	}

	cout << "NO" << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}
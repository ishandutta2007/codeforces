#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>
#include<cstdio>
#include<cassert>
#include<functional>




using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

const long double PI = 3.14159265358979323846;
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const ll mod = 1000 * 1000 * 1000 + 7;
const ll N = 1001;
//const int M = 10000000;

vector<int> z_function(string s) {
	int n = s.size();
	vector<int> z(n);
	for (int i = 1, l = 0, r = 0; i < n; ++i) {
		if (i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];
		if (i + z[i] - 1 > r)
			l = i, r = i + z[i] - 1;
	}
	return z;
}

void solve() {
	string s, t;
	cin >> s >> t;
	ll n = s.size();
	vector<int> z = z_function(t + s);
	vector<int> a(s.size(), 0);
	for (int i = 0; i < a.size(); ++i) {
		if (z[i + t.size()] >= t.size())
			a[i + t.size() - 1] = 1;
	}
	/*vector<int> nextb(a.size(), a.size());
	int x = a.size();
	for (int i = a.size() - 1; i >= 0; --i) {
		if (a[i])
			x = i;
		nextb[i] = x;
	}*/
	vector<ll> d(n, 0), sum(n, 0), sum2(n + 1);
	int prev = -1;
	sum2[0] = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] == 0) {
			if (i)
				d[i] = d[i - 1];
			else
				d[i] = 0;
		}
		else {
			if (prev >= 0)
				d[i] = d[i - 1] + sum2[i - t.size() + 1] - sum2[prev] + i - t.size() + 1 - prev;
			else
				if (i)
					d[i] = d[i - 1] + sum2[i - t.size() + 1] + i - t.size() + 2;
				else
					d[i] = sum2[i - t.size() + 1] + i - t.size() + 2;
			d[i] = ((d[i] % mod) + mod) % mod;
			prev = i - t.size() + 1;
		}
		sum[i] = d[i];
		if (i)
			sum[i] = (sum[i - 1] + d[i]) % mod;
		sum2[i + 1] = (sum[i] + sum2[i]) % mod;
	}
	cout << sum[n - 1] << endl;
}



//#define LOCAL

int main() {
	//ios_base::sync_with_stdio(0);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	solve();


#ifdef LOCAL
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
	return 0;
}
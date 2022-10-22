#include <bits/stdc++.h>
#define int long long
#define fileopen(a, b) freopen(((std::string)a + ".inp").c_str(), "r", stdin); freopen(((std::string)b + ".out").c_str(), "w", stdout);
#define fileopen1(a) freopen(((std::string)a + ".inp").c_str(), "r", stdin); freopen(((std::string)a + ".out").c_str(), "w", stdout);

// #define DEBUG_2

#ifdef DEBUG_2
	#include <chrono>
#endif

using namespace std;

const int MAXN = 1005;
int a[MAXN * 2], b[MAXN * 2], n;

bool is_sorted() {
	for (int i = 1; i < 2 * n; i++)
		if (a[i] > a[i + 1]) return false;
	return true;
}

void q1() {
	for (int i = 1; i < 2 * n; i += 2)
		swap(a[i], a[i + 1]);
}

void q2() {
	for (int i = 1; i <= n; i++)
		swap(a[i], a[i + n]);
}

signed main() {
	#ifdef DEBUG_2
		chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	#endif

	#ifdef PICHU_LOCAL_DEF
		fileopen("input", "output");
	#endif
	#ifndef PICHU_LOCAL_DEF 
		// fileopen1("LAH");
	#endif

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= 2 * n; i++) cin >> a[i], b[i] = a[i];

	if (is_sorted()) return cout << 0, 0;
	int ans = 1e9, cnt = 0;
	for (int i = 1; i <= 2 * n; i++) {
		if (i & 1) q1();
		else q2();
		cnt++;
		if (is_sorted()) {
			ans = min(ans, cnt);
			break;
		}
	}

	cnt = 0;
	for (int i = 1; i <= 2 * n; i++) a[i] = b[i];	
	for (int i = 1; i <= 2 * n; i++) {
		if (i & 1) q2();
		else q1();
		cnt++;
		if (is_sorted()) {
			ans = min(ans, cnt);
			break;
		}
	}
	if (ans == 1000000000) cout << -1; else
	cout << ans;

	#ifdef DEBUG_2
		chrono::steady_clock::time_point end = chrono::steady_clock::now();
		std::cout << std::endl;
		std::cout << "Time difference = " << chrono::duration_cast<chrono::milliseconds> (end - begin).count() << "[ms]" << std::endl;
	#endif
}
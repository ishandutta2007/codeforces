#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <assert.h>
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;

void add(int& a, int b) {
	a += b;
	if (a >= mod) {
		a -= mod;
	}
}

void sub(int& a, int b) {
	a -= b;
	if (a < 0) {
		a += mod;
	}
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	//ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	vector<int> primes;
	for (int i = 2; i <= 70; ++i) {
		bool ok = true;
		for (int j = 2; j < i; ++j) {
			if (i % j == 0) {
				ok = false;
				break;
			}
		}
		if (ok) {
			primes.pb(i);
		}
	}

	int k = sz(primes);
	int n;
	cin >> n;
	set<int> s;
	map<int, int> mapa;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		s.insert(x);
		++mapa[x];
	}

	vector<int> dp(1 << k);
	dp[0] = 1;
	for (int x : s) {
		vector<int> nx = dp;
		int t = 0;
		int val = x;
		for (int i = 0; i < k; ++i) {
			while (val % primes[i] == 0) {
				t ^= (1 << i);
				val /= primes[i];
			}
		}
		for (int mask = 0; mask < (1 << k); ++mask) {
			add(nx[mask ^ t], dp[mask]);
		}
		dp.swap(nx);
	}

	int ans = dp[0];
	for (auto it : mapa) {
		for (int j = 1; j < it.second; ++j) {
			add(ans, ans);
		}
	}

	sub(ans, 1);
	cout << ans << "\n";

}
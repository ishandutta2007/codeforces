#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int z = 1;
vector<int> s, d;
map<int, int> ma;
short best[2001][10][5000];

int anser(int n, int m, int x) {
	if(ma.find(x) == ma.end()) {
		ma[x] = z;
		z++;
	}
	// cout << n << ' ' << m << ' ' << x << '\n';
	int xx = x;
	if(best[n][m][ma[x]] > -1) return best[n][m][ma[x]];
	vector<int> v, v2;
	int g = 0;
	while(x) {
		if((x%10) != m) v.push_back(x%10);
		else g++;
		x /= 10;
	}
	if(v.size() == 0 && n == s.size()) {
		return best[n][m][ma[xx]] = (short)g;
	}
	int ans = 999999;
	if(n < s.size()) {
		if(v.size() < 4 && (m == s[n])) { // must get the next guy
			v2 = v;
			v2.push_back(d[n]);
			sort(v2.begin(), v2.end());
			int k = 0;
			while(v2.size()) {
				k *= 10;
				k += v2.back();
				v2.pop_back();
			}
			ans = anser(n+1, m, k) + 1;
			// cout << ans+g << '\n';
			return best[n][m][ma[xx]] = (short)(ans+g);
		}
		else if(v.size() < 4) { // try getting the next guy
			v2 = v;
			sort(v2.begin(), v2.end());
			int k = 0;
			while(v2.size()) {
				k *= 10;
				k += v2.back();
				v2.pop_back();
			}
			ans = min(ans, anser(n, s[n], k) + abs(s[n]-m));
		}
	}
    // go to a floor, drop off some guy
	v2 = v;
	sort(v2.begin(), v2.end());
	int k = 0;
	while(v2.size()) {
		k *= 10;
		k += v2.back();
		v2.pop_back();
	}
	for(int i : v) { // drop off guy to floor i
		ans = min(ans, anser(n, i, k) + abs(m-i));
	}
	// cout << ans+g << '\n';
	return best[n][m][ma[xx]] = ans+g;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, z = 0;
	cin >> n;
	s.resize(n); d.resize(n);
	for(int i = 0; i <= n; i++) {
		if(i < n) cin >> s[i] >> d[i];
		for(int j = 0; j < 10; j++) {
			for(int k = 0; k < 5000; k++) {
				best[i][j][k] = (short)(-1);
			}
		}
	}
	cout << anser(0, 1, 0) << '\n';
}
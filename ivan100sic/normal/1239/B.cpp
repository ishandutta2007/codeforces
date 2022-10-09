#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
int n;
string s;
 
int E(char x) {
	return x == '(' ? 1 : -1;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);
 
	cin >> n >> s;
	if (count(s.begin(), s.end(), '(') != count(s.begin(), s.end(), ')')) {
		cout << "0\n1 1\n";
		return 0;
	}
 
	vector<int> sol;
	int mins_cnt = 0, rot = 0;
	{
		int val = 0, mn = 123123123, cnt = 0, j = 0;
		for (int i=0; i<n; i++) {
			val += E(s[i]);
			if (val < mn) {
				mn = val;
				cnt = 1;
				j = i+1;
			} else if (val == mn) {
				cnt++;
			}
		}
		rotate(s.begin(), s.begin()+j, s.end());
		sol = {cnt, 1, 1};
		mins_cnt = cnt;
		rot = j;
	}
 
	// spusti parce od +2?
	{
		int lo = -1, ro = -1, vo = -123123123, val = 0, str = 0;
		int lc = -1;
		for (int i=0; i<2*n; i++) {
			val += E(s[i%n]);
			if (val == 2) {
				str++;
				if (lc == -1)
					lc = i;
				if (str > vo)
					lo = lc, ro = i+1, vo = str;
			} else if (val == 1) {
				lc = -1;
				str = 0;
			}
		}
 
		sol = max(sol, vector<int>{mins_cnt + vo, lo, ro});
	}
 
	// podigni sve osim nekog parceta od 1+
	{
		int lo = -1, ro = -1, vo = -123123123, val = 0, str = 0;
		int lc = -1;
		for (int i=0; i<2*n; i++) {
			val += E(s[i%n]);
			if (val == 0) {
				if (str > vo)
					vo = str, lo = lc, ro = i;
				str = 0, lc = -1;
			} else if (val == 1) {
				str++;
				if (lc == -1)
					lc = i;
			}
		}
		sol = max(sol, vector<int>{vo, lo, ro});
	}
 
	cout << sol[0] << '\n' << (sol[1] + rot) % n + 1 << ' ' << (sol[2] + rot) % n + 1 << '\n';
 
}
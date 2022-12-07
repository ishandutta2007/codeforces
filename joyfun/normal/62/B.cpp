#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int inf = 0x3f3f3f3f;
int n, k;
vi v[26];
string s;

int main() {
	scanf("%d%d", &n, &k);
	cin >> s;
	for (int i = 0; i < k; i++) v[s[i] - 'a'].pb(i);
	for (int i = 0; i < n; i++) {
		cin >> s;
		ll ans = 0;
		for (int j = 0; j < s.length(); j++) {
			int c = s[j] - 'a';
			if (sz(v[c]) == 0) ans += s.length();
			else {
				int vs = lower_bound(v[c].begin(), v[c].end(), j) - v[c].begin();
				int len = inf;
				if (vs - 1 >= 0) len = min(len, abs(j - v[c][vs - 1]));
				if (vs < sz(v[c])) len = min(len, abs(j - v[c][vs]));
				ans += len;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
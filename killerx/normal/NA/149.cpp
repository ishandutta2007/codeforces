#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1e5 + 5, m = 6;
int a[m], n, b[mxn], cnt[mxn];

int main() {
	rep(i, m) scanf("%d", &a[i]);
	scanf("%d", &n);
	rep(i, n) scanf("%d", &b[i]);
	vector <pair <int, int> > vec;
	rep(i, n) rep(j, m) vec.pb(mp(b[i] - a[j], i));
	sort(vec.begin(), vec.end());
	int ans = 1e9 + 7;
	int j = 0, z = n;
	rep(i, vec.size()) {
		if (!cnt[vec[i].second]) -- z;
		cnt[vec[i].second] ++;
		while (j <= i && cnt[vec[j].second] > 1) -- cnt[vec[j ++].second];
//		rep(k, n) cerr << cnt[k] << " ";
//		cerr << endl;
		if (!z) ans = min(ans, vec[i].first - vec[j].first);
	}
	printf("%d\n", ans);
	return 0;
}
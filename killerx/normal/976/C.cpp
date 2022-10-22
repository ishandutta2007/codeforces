#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 3e5 + 5;
int n;
int l[mxn], r[mxn];

int main() {
	scanf("%d", &n);
	rep(i, n) scanf("%d %d", &l[i], &r[i]);
	vector <pair <pair <int, int>, int> > v;
	rep(i, n) v.pb(mp(mp(r[i], -l[i]), i));
	sort(v.begin(), v.end());
	set <pair <int, int> > avai;
	rep(xx, n) {
		int i = v[xx].second;
		if (!avai.empty() && avai.rbegin()->first >= l[i]) {
			printf("%d %d\n", avai.rbegin()->second + 1, i + 1);
			return 0;
		}
		avai.insert(mp(l[i], i));
	}
	printf("-1 -1\n");
	return 0;
}
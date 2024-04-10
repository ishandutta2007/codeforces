#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

void Main() {
	int n;
	scanf("%d", &n);
	vector <int> a(n), vz, vv;
	rep(i, n) {
		scanf("%d", &a[i]);
		if (a[i] == 0) vz.pb(i);
		else vv.pb(i);
	}
	map <int, pair <int, int> > M;
	rep(i, vv.size()) {
		int ps = lower_bound(vz.begin(), vz.end(), vv[i]) - vz.begin();
		if (ps >= vz.size() / 2)
			M[a[vv[i]]].second = max(M[a[vv[i]]].second, (int) vz.size() - ps);
		else
			M[a[vv[i]]].first = max(M[a[vv[i]]].first, ps);
	}
	vector <pair <int, int> > v;
	rep(i, n + 1) if (M.find(i) != M.end()) v.pb(M[i]);
//	rep(i, v.size()) cerr << v[i].first << " " << v[i].second << endl;
	vector <vector <int> > ql(vz.size() + 1), qr(vz.size() + 1);
	rep(i, v.size()) ql[v[i].first].pb(i);
	rep(i, v.size()) qr[v[i].second].pb(i);
	vector <bool> used(v.size());
	set <pair <int, int> > can;
	can.clear();
	for (int i = vz.size(); ~i; -- i) {
		if (can.size()) {
			used[can.begin()->second] = 1;
			can.erase(can.begin());
		}
		rep(j, ql[i].size()) {
			pair <int, int> p(v[ql[i][j]].second, ql[i][j]);
			if (!used[p.second]) can.insert(p);
		}
	}
	can.clear();
	for (int i = vz.size(); ~i; -- i) {
		if (can.size()) {
			used[can.begin()->second] = 1;
			can.erase(can.begin());
		}
		rep(j, qr[i].size()) {
			pair <int, int> p(v[qr[i][j]].first, qr[i][j]);
			if (!used[p.second]) can.insert(p);
		}
	}
	int ans = 0;
	rep(i, v.size()) ans += used[i];
	printf("%d\n", min(ans, (int) vz.size() / 2));
}

int main() {
	int t; scanf("%d", &t);
	while (t --) Main();
	return 0;
}
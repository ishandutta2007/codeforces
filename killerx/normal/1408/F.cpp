#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

struct ANS {
	vector <int> v1, v2;
	vector <pair <int, int> > ans;
	void solve(const vector <int>& v, vector <pair <int, int> >& ans) {
		if (v.size() == 1) return ;
		int m = v.size() >> 1;
		vector <int> vl, vr;
		rep(i, m) vl.pb(v[i]);
		rep(i, m) vr.pb(v[i + m]);
		solve(vl, ans);
		solve(vr, ans);
		rep(i, m) ans.pb(mp(vl[i], vr[i]));
	}
	void add(int x) {
		if (v1.size() < v2.size()) swap(v1, v2);
		v2.pb(x);
		int k = 0;
		while ((1 << k) < v2.size()) ++ k;
		int lft = (1 << k) - v2.size();
		while (lft --) v2.pb(v1.back()), v1.pop_back();
		solve(v2, ans);
		if (v1.size() < v2.size()) swap(v1, v2);
	}
	void print() {
		cerr << "- "; rep(i, v1.size()) cerr << v1[i] << " "; cerr << endl;
		cerr << "- "; rep(i, v2.size()) cerr << v2[i] << " "; cerr << endl;
		cerr << endl;
	}
};

ANS solve(int n) {
	if (n == 1) {
		ANS T;
		T.v1.pb(0);
		return T;
	}
	ANS S = solve(n >> 1);
	ANS T;
	rep(i, S.v1.size()) T.v1.pb(S.v1[i]);
	rep(i, S.v1.size()) T.v1.pb(S.v1[i] + (n >> 1));
	rep(i, S.v2.size()) T.v2.pb(S.v2[i]);
	rep(i, S.v2.size()) T.v2.pb(S.v2[i] + (n >> 1));
	rep(i, S.ans.size()) T.ans.pb(mp(S.ans[i].first, S.ans[i].second));
	rep(i, S.ans.size()) T.ans.pb(mp(S.ans[i].first + (n >> 1), S.ans[i].second + (n >> 1)));
	rep(i, S.v1.size()) T.ans.pb(mp(T.v1[i], T.v1[i + S.v1.size()]));
	rep(i, S.v2.size()) T.ans.pb(mp(T.v2[i], T.v2[i + S.v2.size()]));
	if (n & 1) T.add(n - 1);
	return T;
}

int x[15005];

int main() {
	int n;
	scanf("%d", &n);
	vector <pair <int, int> > ans = solve(n).ans;
	printf("%d\n", (int)(ans.size()));
	rep(i, ans.size()) printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
	// rep(i, n) x[i] = rand();
	// rep(i, ans.size()) {
	// 	int t = x[ans[i].first] ^ x[ans[i].second];
	// 	x[ans[i].first] = x[ans[i].second] = t;
	// }
	// set <int> st;
	// rep(i, n) st.insert(x[i]);
	// for (set <int>::iterator it = st.begin(); it != st.end(); ++ it) cerr << *it << " ";
	// cerr << endl;
	return 0;
}
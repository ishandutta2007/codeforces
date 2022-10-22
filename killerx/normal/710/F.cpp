#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int sigma = 26, mxn = 3e5 + 5, B = 7, nB = 7;

class AC {
public:
	vector <pair <string, int> > vs;
	AC() { clear(); }
	int size() const {
		return tot;
	}
	void build() {
		tot = 0; rt = nd();
		rep(i, vs.size()) {
			int u = rt;
			rep(j, vs[i].first.size()) {
				int c = vs[i].first[j] - 'a';
				if (!go[u][c]) go[u][c] = nd();
				u = go[u][c];
			}
			cnt[u] += vs[i].second;
		}
		que.clear();
		rep(c, sigma) {
			int& u = go[rt][c];
			if (u) {
				fail[u] = rt;
				cnt[u] += cnt[fail[u]];
				que.pb(u);
			} else {
				u = rt;
			}
		}
		rep(i, que.size()) {
			int u = que[i];
			rep(c, sigma) {
				int& v = go[u][c];
				if (v) {
					fail[v] = go[fail[u]][c];
					cnt[v] += cnt[fail[v]];
					que.pb(v);
				} else {
					v = go[fail[u]][c];
				}
			}
		}
	}
	void clear() {
		vs.clear();
		build();
	}
	ll qry(const string& s) {
		int u = rt;
		ll ans = 0;
		rep(i, s.size()) {
			int c = s[i] - 'a';
			u = go[u][c];
			ans += cnt[u];
		}
		return ans;
	}
private:
	int go[mxn][sigma];
	int fail[mxn], cnt[mxn];
	vector <int> que;
	int tot, rt;
	int nd() {
		memset(go[tot], 0, sizeof(go[tot]));
		fail[tot] = 0;
		cnt[tot] = 0;
		return tot ++;
	}
};

class ACP {
public:
	ACP() { lim[0] = B; lv = 1; }
	void lvl() { lim[lv] = lim[lv - 1] * B; lv ++; }
	void ins(const string& s, int coef) {
		va[0].vs.pb(mp(s, coef));
		int i = 0;
		while (va[i].size() > lim[i]) {
			if (i + 1 == lv) lvl();
			rep(j, va[i].vs.size()) va[i + 1].vs.pb(va[i].vs[j]);
			va[i].clear();
			++ i;
		}
		va[i].build();
	}
	ll qry(const string& s) {
		ll ans = 0;
		rep(i, lv) ans += va[i].qry(s);
		return ans;
	}
private:
	int lim[nB];
	AC va[nB];
	int lv;
} ACP;

char temp[mxn];
string s;

int main() {
	int q;
	scanf("%d", &q);
	while (q --) {
		int tp;
		scanf("%d %s", &tp, temp);
		s = temp;
		if (tp == 1) ACP.ins(s, 1);
		else if (tp == 2) ACP.ins(s, -1);
		else printf("%lld\n", ACP.qry(s)), fflush(stdout);
	}
	return 0;
}
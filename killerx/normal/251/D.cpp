#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

struct LB {
	ll v[60];
	bitset <100005> ids[65];
	LB() { memset(v, 0, sizeof(v)); }
	void ins(ll x, int id) {
		bitset <100005> nw;
		nw.set(id);
		vector <int> usd;
		for (int i = 60 - 1; ~i; -- i) if (x >> i & 1) {
			if (!v[i]) {
				v[i] = x;
				rep(j, usd.size())
					nw ^= ids[usd[j]];
				ids[i] = nw;
				return ;
			} else {
				x ^= v[i];
				usd.pb(i);
//				nw ^= ids[i];
			}
		}
	}
} lb;

int n;
string x[100005], nx[100005];

bool grp[100005];

string vxor(string a, string b) {
	rep(i, a.size()) a[i] = (a[i] != b[i]) + '0';
	return a;
}

int main() {
	scanf("%d", &n);
	rep(i, n) {
		ll v; scanf("%lld", &v);
		x[i] = bitset <60> (v).to_string();
	}
	string s(60, '0');
	rep(i, n) s = vxor(s, x[i]);
	vector <int> ord;
	rep(i, s.size()) if (s[i] == '0') ord.pb(i);
	rep(i, s.size()) if (s[i] == '1') ord.pb(i);
	rep(i, n) {
		rep(j, ord.size()) nx[i].pb(x[i][ord[j]]);
		lb.ins(bitset <60> (nx[i]).to_ullong(), i);
	}
	bitset <100005> nw;
	ll ans = 0;
	for (int i = 60 - 1; ~i; -- i) {
		if ((lb.v[i] ^ ans) > ans) {
			nw ^= lb.ids[i];
			ans = lb.v[i] ^ ans;
		}
	}
	rep(i, n) if (nw.test(i)) grp[i] = 1;
	rep(i, n) printf("%d%c", grp[i] + 1, " \n"[i + 1 == n]);
	return 0;
}
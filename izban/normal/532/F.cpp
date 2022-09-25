#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;

const int maxn = 1 << 18;
const int mod[2] = { 777777799, 778777781 };
const int _q[2] = {557, 997};

struct Hash {
	int a[2];

	Hash() {
		a[0] = a[1] = 0;
	}

	Hash operator+ (const Hash &h) {
		Hash res;
		for (int i = 0; i < 2; i++) {
			res.a[i] = (a[i] + h.a[i]) % mod[i];
		}
		return res;
	}

	Hash operator- (const Hash &h) {
		Hash res;
		for (int i = 0; i < 2; i++) {
			res.a[i] = (a[i] - h.a[i] + mod[i]) % mod[i];
		}
		return res;
	}

	Hash operator* (const int d) {
		Hash res;
		for (int i = 0; i < 2; i++) {
			res.a[i] = (a[i] * 1LL * d) % mod[i];
		}
		return res;
	}

	Hash operator* (const Hash &h) {
		Hash res;
		for (int i = 0; i < 2; i++) {
			res.a[i] = (1LL * a[i] * h.a[i]) % mod[i];
		}
		return res;
	}

	bool operator< (const Hash &h) const {
		if (a[0] != h.a[0]) return a[0] < h.a[0];
		return a[1] < h.a[1];
	}

	bool operator== (const Hash &h) const {
		return a[0] == h.a[0] && a[1] == h.a[1];
	}
};

int n, m;
char s[maxn], t[maxn];
Hash p[maxn];


int main() {
#ifndef ONLINE_JUDGE
	freopen("task.in", "r", stdin);
#endif

	p[0] = Hash();
	p[0].a[0] = p[0].a[0] = 1;
	Hash q;
	q.a[0] = _q[0];
	q.a[1] = _q[1];
	for (int i = 1; i < maxn; i++) {
		p[i] = p[i - 1] * q;
	}

	while (scanf("%d%d\n", &n, &m) == 2) {
		scanf("%s\n", s);
		scanf("%s\n", t);

		vector<Hash> v1(26);
		vector<Hash> v2(26);
		for (int i = 0; i < m; i++) {
			v1[s[i] - 'a'] = v1[s[i] - 'a'] + p[i];
			v2[t[i] - 'a'] = v2[t[i] - 'a'] + p[i];
		}

		vector<int> ans;
		for (int i = 0; i + m <= n; i++) {
			//...
			vector<pair<Hash, int> > v3;
			for (int j = 0; j < 26; j++) v3.push_back(make_pair(v2[j], j));
			//vector<char> was(26);

			sort(v3.begin(), v3.end());
			bool ok = 1;
			for (int j = 0; j < 26; j++) {
				if (v1[j].a[0] == 0 && v1[j].a[1] == 0) continue;
				int id = lower_bound(v3.begin(), v3.end(), make_pair(v1[j], -1)) - v3.begin();
				if (id == v3.size() || !(v3[id].first == v1[j])) {
					ok = 0;
					break;
				}
				int o = v3[id].second;
				//was[o] = 1;
				if (o == j) continue;
				ok &= v2[j] == v1[o];
			}
			//for (int j = 0; j < 26; j++) ok &= was[j] || v2[j].a[0] == 0 && v2[j].a[1] == 0;
			if (ok) ans.push_back(i + 1);

			v1[s[i] - 'a'] = v1[s[i] - 'a'] - p[i];
			if (i + m < n) {
				v1[s[i + m] - 'a'] = v1[s[i + m] - 'a'] + p[i + m];
			}
			for (int j = 0; j < 26; j++) {
				v2[j] = v2[j] * p[1];
			}
		}
		printf("%d\n", ans.size());
		for (int i = 0; i < (int)ans.size(); i++) printf("%d%c", ans[i], " \n"[i + 1 == (int)ans.size()]);
	}

	return 0;
}
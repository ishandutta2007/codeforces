#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 500005;
const llint MOD = 1000000007;

llint n, m, k, cnt, sol;
llint c[MAXN], bio[MAXN], pot[MAXN];
vector < pair <llint, llint> > v[MAXN];
vector <llint> r;
unordered_map <llint, vector <llint> > mp;

void precompute () {
	pot[0] = 1;
	for (int i=1; i<MAXN; i++) {
		pot[i] = pot[i-1] * 2 % MOD;
	}
	sol = pot[k] * pot[n] % MOD;
}

void dfs (llint cvor, llint val) {
	if (bio[cvor]) return;
	bio[cvor] = 1;
	cnt--;
	int ind = lower_bound(v[cvor].begin(), v[cvor].end(), make_pair(val, 0LL)) - v[cvor].begin();
	for (int i = ind; i < v[cvor].size() && v[cvor] [i].first == val; i++) {
		int sus = v[cvor] [i].second;
		dfs(sus, val);
	}
}

void obradi (llint val) {
	cnt = n;
	int lim = mp[val].size();
	for (int i=0; i<lim; i++) {
		int cvor = mp[val] [i];
		if (!bio[cvor]) {
			dfs(cvor, val);
			cnt++;
		}
	}
	for (int i=0; i<lim; i++) {
		int cvor = mp[val] [i];
		bio[cvor] = 0;
	}
	sol = (sol - pot[n] + pot[cnt]) % MOD;
	if (sol < 0) sol += MOD;
}

int main () {
	cin >> n >> m >> k;
	precompute();
	for (int i=1; i<=n; i++) {
		scanf("%I64d", &c[i]);
	}
	for (int i=1; i<=m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		llint val = c[a] ^ c[b];
		v[a].push_back(make_pair(val, b));
		v[b].push_back(make_pair(val, a));
		r.push_back(val);
		mp[val].push_back(a);
		mp[val].push_back(b);
	}
	for (int i=1; i<=n; i++) {
		sort(v[i].begin(), v[i].end());
	}
	sort(r.begin(), r.end());
	r.erase(unique(r.begin(), r.end()), r.end());
	for (int i=0; i<r.size(); i++) {
		obradi(r[i]);
	}
	cout << sol;
	return 0;
}
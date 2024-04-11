#define SolutionToA 8bd96cf2dcad0ec7e9afce582c4bd1390179f4dec00841d13edc4420ce7de42b
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using ll = long long;
using namespace std;
const int maxn = 1e3 + 33, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MAXN = (1 << 20);

template <class T>
struct fenwick
{
	int sz;
	T tr[MAXN];

	void init(int n)
	{
		sz = n + 1;
		memset(tr, 0, sizeof(tr));
	}

	T query(int idx)
	{
		T ans = 0;
		for(; idx >= 1; idx -= (idx & -idx))
			ans += tr[idx];
		return ans;
	}

	void update(int idx, T val)
	{
		if(idx <= 0) return;
		for(; idx <= sz; idx += (idx & -idx))
			tr[idx] += val;
	}

	T query(int l, int r) { return query(r) - query(l - 1); }
};
vector<int> c[26];
string s;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
		c[s[i]-'a'].push_back(i);
	}
	for(int i = 0; i < 26; i++) reverse(all(c[i]));
	reverse(all(s));
	fenwick<int> f;f.init(s.size()+3);
	ll ans = 0;
	for(auto &i : s) {
		int cur = 1 + c[i-'a'].back();
		c[i-'a'].pop_back();
		ans += f.query(cur, n);
		f.update(cur, 1);
		//cout << cur << " ";
	}
	cout << ans << '\n';
	
}
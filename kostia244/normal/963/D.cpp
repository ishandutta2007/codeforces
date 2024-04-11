//#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 1e5 + 33, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int sigma = 26, C = 333;
int n, q;
string s;
int k[maxn], len[maxn], ans[maxn];
vi pos[maxn];
struct aho {
	int to[maxn][sigma], link[maxn], id[maxn], sz = 1;
	void add_string(string &s, int i) {
		int cur = 0;
		for(auto c : s) {
			c -= 'a';
			if(!to[cur][c]) to[cur][c] = sz++;
			cur = to[cur][c];
		}
		id[cur] = i;
	}
	void push_links() {
		int q[maxn], s = 0, fi = 0;
		q[fi++] = 0;
		while(s < fi) {
			int U = q[s++];
			int V = link[U];
			for(int i = 0; i < 26; i++) {
				if(to[U][i]) {
					q[fi++] = to[U][i];
					link[to[U][i]] = U?to[V][i]:0;
				} else {
					to[U][i] = to[V][i];
				}
			}
		}
	}
	void upd(int p, int x) {
		while(p) {
			pos[p].pb(x);
			if(id[p]!=-1&&pos[p].size()>=k[id[p]]) {
				ans[id[p]] = min(ans[id[p]], len[id[p]] + pos[p].back() - pos[p][pos[p].size()-k[id[p]]]);
			}
			p = link[p];
		}
	}
};
int b[maxn];
int baka(int k, string t) {
	int i, j;
	i = 0, j = b[0] = -1;
	while(i < t.size()) {
		while(j != -1 && t[j] != t[i]) j = b[j];
		i++, j++;
		b[i] = j;
	}
	vi x;
	i = 0, j = 0;
	while(i < s.size()) {
		while(j != -1 && t[j] != s[i]) j = b[j];
		i++, j++;
		if(j==t.size()) {
			x.pb(i-1);
			j = b[j];
		}
	}
	int ans = 1<<30;
	for(int i = k-1; i < x.size(); i++) ans = min(ans, x[i] - x[i-k+1]);
	return t.size() + ans;
}
aho a;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	n = s.size();
	cin >> q;
	string t;
	memset(a.id, -1, sizeof a.id);
	memset(ans, 0x3d, sizeof ans);
	for(int i = 0; i < q; i++) {
		cin >> k[i] >> t;
		len[i] = t.size();
		if(t.size()>C) ans[i] = baka(k[i], t);
		else {
			a.add_string(t, i);
		}
	}
	a.push_links();
	for(int cur = 0, i = 0; i < n; i++) {
		cur = a.to[cur][s[i]-'a'];
		a.upd(cur, i);
	}
	for(int i = 0; i < q; i++) {
		if(ans[i]>n) ans[i] = -1;
		cout << ans[i] << '\n';
	}
}
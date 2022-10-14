#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 1<<20, mod = 1e9 + 7;
int len[maxn], diff[maxn], link[maxn], slink[maxn];
map<int, int> to[maxn];
int sz, cur;
basic_string<int> s;
void init() {
	len[0] = -1;
	sz = 2, cur = 0;
}
bool bad(int v) { return (int)s.size()-len[v]-2 < 0 || s.back() != s[s.size()-len[v]-2]; }
int find_link(int v) {
	if(!bad(v)) return v;
	while(bad(link[v])) v = slink[v];
	return link[v];
}

int aux[maxn], dp[maxn];
int scalc(int v) {
	aux[v] = dp[s.size()-len[slink[v]]-diff[v]];
	if(slink[v]^link[v]) aux[v] = (aux[v] + aux[link[v]])%mod;
	return aux[v];
}

void add(int c) {
	s += c;
	cur = find_link(cur);
	if(!to[cur][c]) {
		len[sz] = len[cur]+2;
		link[sz] = max(1, to[find_link(link[cur])][c]);
		diff[sz] = len[sz]-len[link[sz]];
		slink[sz] = diff[link[sz]] == diff[sz] ? slink[link[sz]] : link[sz];
		to[cur][c] = sz++;
	}
	cur = to[cur][c];
	for(int v = cur; v>1; v = slink[v])
		(dp[s.size()] += scalc(v))%=mod;
}
int hsh[maxn], pw[maxn];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int B = 26 + (rng()%6969696) + 9;
int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	pw[0] = 1;
	for(int i = 1; i < maxn; i++) pw[i] = pw[i-1]*1ll*B%mod;
	string t;cin >> t;
	int n = t.size();
	t = " " + t;
	for(int i = 1; i <= n; i++)
		hsh[i] = (hsh[i-1] + pw[i]*1ll*(t[i]-'a'+1))%mod;
	auto get = [&](int l, int r) { return (mod - hsh[l-1] + hsh[r])*1ll*pw[maxn-1-r]%mod; };
	int l = 1;
	map<int, int> id;
	basic_string<int> v;
	for(int i = 1; i <= n/2; i++) {
		if(get(l, i) == get(n+1-i, n+1-l)) {
			if(!id.count(get(l, i))) id[get(l, i)] = id.size();
			v.push_back(id[get(l, i)]);
			l = i+1;
		}
	}
	if(l-1!=n/2) return cout << "0\n", 0;
	init(), dp[0] = 1;
	for(auto i : v) add(i);
	cout << dp[s.size()] << '\n';
}
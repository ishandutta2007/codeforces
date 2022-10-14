#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 1005000 + 22, mod = 998244353;
const int MAXN = 1005000, sigma = 26;
map<int, int> to[maxn];
int len[maxn], link[maxn], s[maxn], par[maxn];
int last, n, sz;
 
 
void init() {
	for(int i = 0; i < sz; i++) {
		to[i].clear();
	} 
	len[1] = -1;
	link[0] = 1;
	s[0] = -1;
	last = 0;
	sz = 2;
	n = 1;
}
 
int get_link(int v) {
	while(s[n - 1] != s[n - len[v] - 2]) {
		v = link[v];
	}
	return v;
}
 
void add_letter(int c) {
	s[n++] = c;
	last = get_link(last);
	if(!to[last][c]) {
		len[sz] = len[last] + 2;
		link[sz] = to[get_link(link[last])][c];
		to[last][c] = sz++;
	}
	last = to[last][c];
	par[last] = par[link[last]] + 1;
}

int L[MAXN], R[MAXN];
void solve() {
    string s;
    cin >> s;
    init();
    for (int i = s.size(); i--;) {
        add_letter(s[i]);
        L[i] = len[last];
    }
    int _i = 0;
	while(_i < s.size()-_i-1 && s[_i] == s[s.size()-1-_i]) _i++;
    int x = 0, y = 0;
    init();
    for (int i = _i, L = 1; i < s.size()-_i; i++, L++) {
        add_letter(s[i]);
        if(len[last]==L)
        x = max(x, len[last]);
    }
    init();
    for (int i = s.size()-_i, L = 1; i-- > _i; L++) {
        add_letter(s[i]);
        if(len[last]==L)
        y = max(y, len[last]);
    }
    if(y<x) y = 0;
    else x = 0;
    x+=_i, y +=_i;
	for(int i = 0; i < x; i++) cout << s[i];
	for(int i = s.size()-y; i < s.size(); i++) cout << s[i];
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}
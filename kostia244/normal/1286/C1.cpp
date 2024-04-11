#pragma GCC optimize("trapv")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using ld = long double;
#include<bits/extc++.h>
using namespace __gnu_pbds;
using oset = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 1<<21, mod = 1e9 + 7;
int soc(const map<char, int> &t) {
	int ans = 0;
	for(auto i : t) ans += i.second;
	return ans;
}
int local = 0;
string S = "ssssszszsszszzszzzzs";
int n, n1, n2;
map<int, int> cntsuf;
string hv;
map<char, int> conv(string& s) {
	map<char, int> t;
	for(auto i : s) t[i]++;
	return t;
}
vector<map<char, int>> query(int l, int r) {
	l++, r++;
	vector<map<char, int>> ans;
	cout << "? " << l << " " << r << endl;
	for(int i = l; i <= r; i++)
		for(int j = i; j <= r; j++) {
			string s; local?s=S.substr(i-1, j-i+1), 0:(cin >> s, 0);
			ans.pb(conv(s));
		}
	return ans;
}
void guess_pref() {
	map<map<char, int>, int> c;
	for(auto i : query(0, n1-1)) c[i]++;
	for(auto i : query(1, n1-1)) c[i]--;
	vector<map<char, int>> t;
	for(auto i : c) if(i.second) t.pb(i.first);
	sort(all(t), [](auto a, auto b) {return soc(a) < soc(b);});
	for(int i = (int)t.size(); i--;) {
		if(i) for(auto x : t[i-1]) t[i][x.first] -= x.second;
		for(auto x : t[i]) if(x.second==1) hv[i] = x.first;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	local?n=S.size(), 0:(cin >> n, 0);
	if(n == 1) {
		char x = query(0, 0)[0].begin()->first;
		cout << "! " << x << endl;
		return 0;
	}/*
	if(n == 2) {
		char x = query(0, 0)[0].begin()->first;
		char y = query(1, 1)[0].begin()->first;
		cout << "! " << x << y << endl;
		return 0;
	}
	n2 = n/2, n1 = n - n2;*/
	hv = string(n, '.');
	n1 = n;
	guess_pref();
	cout << "! " << hv << endl;
}
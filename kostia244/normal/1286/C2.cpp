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
string S = "abcd";
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
//#define DBG(x) x

map<char, int> lst;
map<map<char, int>, int> byl[111];
int p, s;
map<char, int> inv(map<char, int> t) {
	map<char, int> r = byl[n].begin()->first;
	for(auto i : t) r[i.first]-=i.second;
	return r;
}
map<char, int> trim(map<char, int> mp) {
	map<char, int> a;
	for(auto &i : mp) if(i.second) a[i.first] = i.second;
	return a;
}
map<map<char, int>, int> guessable(int l) {
	map<map<char, int>, int> ans;
	//DBG(cout << "GUESSING" << l << ":\n";)
	for(int i = 1; i+l <= n; i++) {
		map<char, int> t = byl[n].begin()->first;
		//DBG(cout << hv.substr(0, i) << " " << hv.substr(i+l, n) << '\n';)
		for(int j = 0; j < i; j++) t[hv[j]]--;
		for(int j = i+l; j < n; j++) t[hv[j]]--;
		//DBG(for(auto i : t) cout << "(" << i.first << ", " << i.second << "),";cout << ";\n";)
		ans[trim(t)]++;
	}
	//DBG(cout << ":::\n";)
	return ans;
}
void guess_suff() {
	for(auto i : query(0, n-1)) {
		//DBG(for(auto i : i) cout << "(" << i.first << ", " << i.second << "),";cout << ";\n";)
		byl[soc(i)][i]++;
	}
	p = n1, s = 0;
	map<char, int> x, y;
	int cur = n-1;
	//DBG(cout << hv << '\n';)
	//DBG(for(int i = 1; i <= n; i++) cout << byl[i].size() << " " << i << "\n";)
	while(p+s+1 < n) {
		//DBG(cout << "guessable:\n";)
		for(auto i : guessable(cur)) {
			//DBG(cout << i.second << "\n";)
			//DBG(for(auto j : i.first) cout << "(" << j.first << ", " << j.second << "),";cout << ";\n";)
			byl[cur][i.first]-=i.second;
		}
		//DBG(cout << "nonzero:\n";)
		for(auto i : byl[cur]) 
			if(i.second) {
				//DBG(cout << i.second << "\n";)
				//DBG(for(auto j : i.first) cout << "(" << j.first << ", " << j.second << "),";cout << ";\n";)
				x = i.first;
			}
		x = y = inv(x);
		for(auto i : lst) x[i.first] -= i.second;
		for(auto i : x) if(i.second) hv[cur] = i.first, //DBG(cout << cur << " " << i.first << '\n');
		lst = y;
		//DBG(cout << hv << '\n';)
		cur--;
		s++;
	}
	map<char, int> t = byl[n].begin()->first;
	for(auto i : hv) if(i!='.') t[i]--;
	for(auto i : t) if(i.second) hv[n1] = i.first;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	local?n=S.size(), 0:(cin >> n, 0);
	if(n == 1) {
		char x = query(0, 0)[0].begin()->first;
		cout << "! " << x << endl;
		return 0;
	}
	if(n == 2) {
		char x = query(0, 0)[0].begin()->first;
		char y = query(1, 1)[0].begin()->first;
		cout << "! " << x << y << endl;
		return 0;
	}
	n2 = n/2, n1 = n - n2;
	hv = string(n, '.');
	guess_pref();
	guess_suff();
	cout << "! " << hv << endl;
}
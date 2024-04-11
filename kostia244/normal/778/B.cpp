#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 5050, mod = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
struct op {
	string field;
	int type = 0, l = 0, r = 0;
};
op u[5030];
map<string, int> id;
int sz = 1;
void read_op(string s) {
	int p = s.find(' ');
	string x = s.substr(0, p);
	id[x] = sz;
	string y = s.substr(p+4);
	int _xor = y.find("XOR");
	int _or = y.find("OR");
	int _and = y.find("AND");
	if(_xor != string::npos) {
		u[sz].type = 1;
		string a = y.substr(0, _xor-1);
		string b = y.substr(_xor+4);
		u[sz].l = id[a];
		u[sz].r = id[b];
	} else if(_or != string::npos) {
		u[sz].type = 2;
		string a = y.substr(0, _or-1);
		string b = y.substr(_or+3);
		u[sz].l = id[a];
		u[sz].r = id[b];
	} else if(_and != string::npos) {
		string a = y.substr(0, _and-1);
		string b = y.substr(_and+4);
		u[sz].type = 3;
		u[sz].l = id[a];
		u[sz].r = id[b];
	} else {
		u[sz].field = y;
	}
	sz++;
}
int val[maxn];
int eval(int b, int i) {
	if(u[i].type == 0)
		return val[i] = u[i].field[b]-'0';
	if(u[i].type == 1) 
		return val[i] = val[u[i].l] ^ val[u[i].r];
	if(u[i].type == 2)
		return val[i] = val[u[i].l] | val[u[i].r];
	return val[i] = val[u[i].l] & val[u[i].r];
}
int test(int b, int v) {
	int ans = 0;
	val[0] = v;
	for(int i = 1; i < sz; i++) {
		int t = eval(b, i);
		ans += t;
	}
	return ans;
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	id["?"] = 0;
	int n, m;
	cin >> n >> m;
	string s;
	getline(cin, s);
	for(int i = 0; i < n; i++) {
		getline(cin, s);
		read_op(s);
	}
	for(int i = 0; i < m; i++)
		cout << char('0' + (test(i, 1)<test(i, 0)));
	cout << endl;
	for(int i = 0; i < m; i++)
		cout << char('0' + (test(i, 1)>test(i, 0)));
	cout << endl;
}
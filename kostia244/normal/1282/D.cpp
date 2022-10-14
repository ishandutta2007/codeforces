//#pragma GCC optimize("trapv")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,tune=native")
#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vvi = vector<vi>;
using ld = long double;
const int maxn = 505, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int q(string s) {
	cout << s << endl;
	int t;
	cin >> t;
	if (t == 0)
		exit(0);
	return t;
}
int aa, bb;
string get(char c, int x) {
	string s = "";
	while (x--)
		s += c;
	return s;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s = "";
	aa = q("a");
	int qqq = aa;
	if(qqq==300) {
		q(get('b', 300));
	}
	int t = q(get('a', aa + 1));
	if (t == aa + 1) {
		q(get('b', qqq));
	}
	int len = aa + 1;
	string cur = "";
	int bcnt = t, acnt = len - t;
	while (bcnt) {
		string a = cur + "b" + get('a', acnt);
		t = q(a);
		if (t + a.size() == len) {
			cur += 'b';
			bcnt--;
		} else {
			cur += 'a';
			acnt--;
		}
	}
}
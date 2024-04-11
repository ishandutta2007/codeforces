#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first.first
#define yy first.second
#define __V vector
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define oit ostream_iterator
#define mod 1000000007ll
using namespace __gnu_pbds;
using namespace std;
void doin() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
#ifdef LOCAL
//		freopen("in", "r", stdin);
//		freopen("out", "w", stdout);
#endif
}
template<typename T>
void getv(T& a, int n) {
	a.resize(n);
	for (auto& i : a)
		cin >> i;
}
typedef long long ll;
typedef double ld;
typedef int _I;
typedef pair<_I, _I> pi;
typedef pair<ld, ld> pd;
typedef map<_I, _I> mii;
typedef __V <_I> vi;
typedef __V <char> vc;
typedef __V <ld> vd;
typedef __V <vd> vvd;
typedef __V <pi> vpi;
typedef __V <__V<_I>> vvi;
typedef __V <__V<char>> vvc;
typedef __V <__V<pi>> vvpi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n;

void test() {
	string s, t[2];
	cin >> s;
	for(auto i : s)
		t[i&1]+=i;
	for(int i = 0; i < t[0].size(); i++)
		for(int j = 0; j < t[1].size(); j++)
			if(abs(0+t[0][i]-t[1][j]) != 1) {
				cout << t[0].substr(0, i);
				cout << t[0].substr(i+1, t[0].size());
				cout << t[0][i];
				cout << t[1][j];
				cout << t[1].substr(0, j);
				cout << t[1].substr(j+1, t[1].size());
				cout << "\n";
				return;
			}
	if(t[0].size() == 0 && t[1].size()){
		cout << t[1] << "\n";return;}
	if(t[1].size() == 0 && t[0].size()) {
		cout << t[0] << "\n";return;}
	cout << "No answer\n";
}

int main() {
	doin();
	cin >> n;
	while(n--)
		test();
}
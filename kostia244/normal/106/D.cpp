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
//#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif
}
template<typename T, typename l>
void getv(T& a, int n, l f) {
	a.resize(n);
	for (auto& i : a)
		cin >> i, f(i);
}
template<typename T>
void getv(T& a, int n) {
	a.resize(n);
	for (auto& i : a)
		cin >> i;
}
typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
typedef ll _I;
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
int n, m, k, l, leftmost[1001][1001], rightmost[1001][1001],
		topmost[1001][1001], bottommost[1001][1001];

struct {
	int i = -1, j = -1;
	void add(int _i, int _j) {
		i = _i, j = _j;
	}
	void a(char c, int l, int k) {
		if(i==-1) return;
		if (c == 'N') {
			if(i-l<0||topmost[i][j]>=(i-l))
				i = -1;
			else
				i = i-l;
		} else if (c == 'S') {
			if(i+l>=n||bottommost[i][j]<=(i+l))
				i = -1;
			else
				i = i+l;
		} else if (c == 'W') {
			if(j-l<0||leftmost[i][j]>=(j-l))
				i = -1;
			else
				j = j-l;
		} else if (c == 'E') {
			if(j+l>=m||rightmost[i][j]<=(j+l))
				i = -1;
			else
				j = j+l;
		}
	}
} ptr[26];

char MAP[1001][1001], c;

int main() {
	doin();
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] >= 'A')
				ptr[MAP[i][j] - 'A'].add(i, j);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			leftmost[i][j] = MAP[i][j] == '#' ? j : leftmost[i][j - 1];
		}
		for (int j = m - 1; j >= 0; j--) {
			rightmost[i][j] = MAP[i][j] == '#' ? j : rightmost[i][j + 1];
		}
	}
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			topmost[i][j] = MAP[i][j] == '#' ? i : topmost[i - 1][j];
		}
		for (int i = n - 1; i >= 0; i--) {
			bottommost[i][j] = MAP[i][j] == '#' ? i : bottommost[i + 1][j];
		}
	}
	cin >> k;
	while(k--) {
		cin >> c >> l;
		for(int i = 0; i < 26; i++)
			ptr[i].a(c, l, i);
	}
	bool a = true;
	for(int i = 0; i < 26; i++)
		if(ptr[i].i != -1)
			 a= false, cout << char('A'+i);
	if(a)
		cout << "no solution";
}
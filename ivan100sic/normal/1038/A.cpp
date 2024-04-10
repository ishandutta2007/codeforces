#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, k;
	string s;
	cin >> n >> k >> s;
	map<char, int> m;
	for (char x : s)
		m[x]++;
	int lo = 12312123;
	for (int i=0; i<k; i++)
		lo = min(lo, m[i+'A']);
	cout << lo*k;
}
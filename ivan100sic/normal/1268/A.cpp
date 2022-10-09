#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k >> s;
	string p = s.substr(0, k), q;
	for (int i=k; i<n; i++)
		p += p[i % k];
	if (p >= s)
		q = p;
	p = p.substr(0, k);
	if (p != string(p.size(), '9')) {
		p.back()++;
		int j = k-1;
		while (p[j] == '9' + 1) {
			p[j] = '0';
			p[--j]++;
		}
	}
	for (int i=k; i<n; i++)
		p += p[i % k];
	if (q == "")
		q = p;
	cout << n << '\n';
	cout << q << '\n';
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int a[105];

int f(int x) {
	return x + (x-1)/k * 5;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=0; i<n; i++) {
		string s;
		cin >> s;
		a[s.size()]++;
	}
	string s;
	cin >> s;
	int l = s.size();

	int u = accumulate(a, a+l, 0);
	cout << f(u+1) << ' ' << f(u+a[l]) << '\n';
}
#include<iostream>
#include<algorithm>

using namespace std;

typedef long long llint;

const int MAXN = 200005;

llint n, s, sol;
llint l[MAXN];

int main () {
	cin >> n >> s;
	for (int i=0; i<n; i++) {
		cin >> l[i];
	}
	sort(l, l+n);
	for (int i=0; i<=n/2; i++) {
		sol += max(0LL, l[i] - s);
	}
	for (int i=n/2; i<n; i++) {
		sol += max(0LL, s - l[i]);
	}
	cout << sol;
	return 0;
}
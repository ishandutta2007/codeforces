#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int l[100005], r[100005], a[100005];

int main() {
	cin >> n >> m;
	int sol = n;
	for (int i=1; i<=m; i++) {
		cin >> l[i] >> r[i];
		sol = min(sol, r[i] - l[i]+1);
	}
	cout << sol << '\n';
	for (int i=0; i<n; i++) {
		cout << i % sol << ' ';
	}
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i=0, j=n*m-1, k=0; i<n*m; i++, k+=j, j=j>0?-j+1:-j-1)
		cout << k/m+1 << ' ' << k%m+1 << '\n';
}
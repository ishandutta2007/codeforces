// Hydro submission #62c6d3738672efa577c01e86@1657197427748
#include <bits/stdc++.h>
using namespace std;
const int N = 1E5 + 1;
int n;
int arr[2][N];
multiset<int> S;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[0][i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> arr[1][i];
	}
	if (arr[0][1] != arr[1][1]) {
		cout << "No" << endl;
		exit(0);
	}
	for (int i = 1; i < n; i++) {
		S.insert(arr[0][i + 1] - arr[0][i]);
	}
	for (int i = 1; i < n; i++) {
		auto iter = S.find(arr[1][i + 1] - arr[1][i]);
		if (iter == S.end()) {
			cout << "No" << endl;
			exit(0);
		}
		S.erase(iter);
	}
	cout << "Yes" << endl;
	return 0;
}
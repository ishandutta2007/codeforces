#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 2038074743;
int n, m;
vector<string> field;
vector<vector<ll>> arr;
vector<vector<ll>> brr;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> m;
	field.resize(n);

	for (int i=0; i<n; i++)
		cin >> field[i];

	arr.resize(n);
	brr.resize(n);
	for (int i=0; i<n; i++) {
		arr[i].resize(m);
		brr[i].resize(m);
	}

	arr[0][0] = 1LL;
	for (int j=1; j<m; j++) {
		if (field[0][j] == '#') arr[0][j] = 0;
		else arr[0][j] = arr[0][j-1];
	}

	for (int i=1; i<n; i++) {
		if (field[i][0] == '#') arr[i][0] = 0;
		else arr[i][0] = arr[i-1][0];
	}

	for (int i=1; i<n; i++) {
		for (int j=1; j<m; j++) {
			if (field[i][j] == '#') arr[i][j] = 0;
			else arr[i][j] = (arr[i-1][j] + arr[i][j-1])%mod;
		}
	}

	brr[n-1][m-1] = 1LL;
	for (int j=m-2; j>=0; j--) {
		if (field[n-1][j] == '#') brr[n-1][j] = 0;
		else brr[n-1][j] = brr[n-1][j+1];
	}

	for (int i=n-2; i>=0; i--) {
		if (field[i][m-1] == '#') brr[i][m-1] = 0;
		else brr[i][m-1] = brr[i+1][m-1];
	}

	for (int i=n-2; i>=0; i--) {
		for (int j=m-2; j>=0; j--) {
			if (field[i][j] == '#') brr[i][j] = 0;
			else brr[i][j] = (brr[i+1][j] + brr[i][j+1])%mod;
		}
	}

	/*
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++)
			cout << arr[i][j] << ' ';
		cout << '\n';
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++)
			cout << brr[i][j] << ' ';
		cout << '\n';
	}
	*/

	int ans = 2;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (i==0 && j==0) continue;
			if (i==n-1 && j==m-1) continue;
			if (arr[i][j] == 0 || brr[i][j] == 0 ) continue;
			if (brr[i][j] * arr[i][j]%mod == arr[n-1][m-1] * brr[n-1][m-1]%mod) ans = 1;
		}
	}

	if (arr[n-1][m-1] == 0) ans = 0;

	cout << ans;
}
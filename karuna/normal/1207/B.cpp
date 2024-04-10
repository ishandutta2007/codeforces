#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
int arr[100][100], brr[100][100];
vector<pii> ans;
bool flag = true;
int main() {
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) cin >> arr[i][j];
	}

	for (int i=0; i<n-1; i++) {
		for (int j=0; j<m-1; j++) {
			if (arr[i][j] == 0) continue;
			if (arr[i][j] == 1 && arr[i+1][j] == 1 && arr[i][j+1] == 1 && arr[i+1][j+1] == 1) {
				brr[i][j] = brr[i+1][j] = brr[i][j+1] = brr[i+1][j+1] = 1;
				ans.push_back(pii(i, j));
			}
		}
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++){
			if (arr[i][j] != brr[i][j]) flag = false;
		}
 	}

 	if (!flag) cout << -1;
 	else {
 		cout << ans.size() << '\n';
 		for (int i=0; i<ans.size(); i++) {
 			cout << ans[i].va+1 << ' ' << ans[i].vb+1 << '\n';
 		}
 	}

}
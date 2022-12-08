#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>

using namespace std;

typedef long long ll;

ll INF = 4e18;
int INFi = 2e9;
double eps = 1e-8;
ll mod = 1e9 + 7;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	vector<vector<int>> b(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> b[i][j];
		}
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != b[i][j]) {
				int ind = j + 1;
				while (ind < m && a[i][ind] == b[i][ind]) ind++;
				if (ind == m) {
					cout << "No\n";
					//system("pause");
					return 0;
				}
				a[i + 1][j] ^= 1;
				a[i + 1][ind] ^= 1;
				a[i][j] ^= 1;
				a[i][ind] ^= 1;
				j = ind;
			}
		}
	}
	/*for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
	cout << a[i][j] << " ";
	}
	cout << endl;
	}*/
	if (b[n - 1] == a[n - 1]) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}
	//system("pause");
	return 0;
}
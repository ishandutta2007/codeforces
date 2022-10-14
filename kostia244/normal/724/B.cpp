#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
const ll mod = 998244353ll;
int n, m, mat[44][44];

bool check(int a, int b) {
	for(int i = 0; i < n; i++) {
		swap(mat[i][a], mat[i][b]);
		int c = 0;
		for(int j = 0; j < m; j++)
			c += (j+1!=mat[i][j]);
		swap(mat[i][a], mat[i][b]);
		if(c > 2)
			return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	if(check(1, 1)) {
		cout << "YES\n";
		return 0;
	}
	for(int i = 0; i < m; i++)
		for(int j = i+1; j < m; j++) {
			if(check(i, j)) {
				cout << "YES\n";
				return 0;
			}
		}
	cout << "NO\n";
}
#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using llf = long double;
using pi = pair<lint, lint>;
const int MAXN = 2005;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int q; cin >> q;
	while(q--){
		int n; cin >> n;
		lint ret = 0;
		vector<vector<lint>> a(2*n, vector<lint>(2*n));
		for(int i = 0; i < n*2; i++){
			for(int j = 0; j < n*2; j++){
				cin >> a[i][j];
				if(i >= n && j >= n) ret += a[i][j];
			}
		}
		ret += min({a[n][0], a[n][n-1], a[n-1][n], a[0][n], a[n-1][2*n-1], a[0][2*n-1], a[2*n-1][0], a[2*n-1][n-1]});
		cout << ret << "\n";
	}
}
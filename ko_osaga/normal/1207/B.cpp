#include <bits/stdc++.h>
#define sz(v) ((int)((v).size()))
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int mod = 998244353;
const int MAXN = 2000005;

int n, m;
int a[55][55], b[55][55];
vector<pi> v;
int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin >> a[i][j];
	for(int i=1; i<n; i++){
		for(int j=1; j<m; j++){
			if(a[i-1][j] && a[i-1][j-1] && a[i][j] && a[i][j-1]){
				v.emplace_back(i-1, j-1);
			}
		}
	}
	for(auto [i, j] : v){
		b[i][j] = b[i+1][j] = b[i][j+1] = b[i+1][j+1] = 1;
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(a[i][j] != b[i][j]){
				puts("-1");
				return 0;
			}
		}
	}
	cout << sz(v) << endl;
	for(auto [i, j] : v){
		printf("%d %d\n", i+1, j+1);
	}
}
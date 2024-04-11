#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int n, m, a[105][105];
int x[105], y[105];

int solve(int b){
	int ans = 0;
	for(int j=0; j<m; j++){
		y[j] = a[0][j] - x[0];
		ans += y[j];
		if(y[j] < 0) return 1e9;
	}
	for(int i=1; i<n; i++){
		x[i] = a[i][0] - y[0];
		ans += x[i];
		if(x[i] < 0) return 1e9;
	}
	ans += x[0];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(x[i] + y[j] != a[i][j]){
				return 1e9;
			}
		}
	}
	if(b == 1){
		printf("%d\n", ans);
		for(int i=0; i<n; i++){
			for(int j=0; j<x[i]; j++) printf("row %d\n", i+1);
		}
		for(int i=0; i<m; i++){
			for(int j=0; j<y[i]; j++) printf("col %d\n", i+1);
		}
	}
	return ans;
}
int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> a[i][j];
		}
	}
	pi ret(1e9, -1);
	for(int i=0; i<=500; i++){
		x[0] = i;
		ret = min(ret, pi(solve(0), i));
	}
	if(ret.first > 1e8){
		cout << -1;
		return 0;
	}
	x[0] = ret.second;
	solve(1);
}
#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
typedef vector<int> vi;

int n, m;
int x[505];

int main(){
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> x[i];
	}
	double dap = 0;
	for(int i=0; i<m; i++){
		int s, e, c;
		cin >> s >> e >> c;
		dap = max(dap, 1.0 * (x[s] + x[e]) / c);
	}
	printf("%.10f", dap);}
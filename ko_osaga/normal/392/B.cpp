#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
typedef vector<int> vi;

int adj[3][3], n;
lint dp[3][3][44];

lint f(int s, int e, int x){
	if(x == 0) return 0;
	if(~dp[s][e][x]) return dp[s][e][x];
	int m = 3 - s - e;
	lint ret1 = f(s, m, x-1) + f(m, e, x-1) + adj[s][e];
	lint ret2 = f(s, e, x-1) + adj[s][m] + f(e, s, x-1) + adj[m][e] + f(s, e, x-1);
	return dp[s][e][x] = min(ret1, ret2);
}

int main(){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cin >> adj[i][j];
		}
	}
	cin >> n;
	memset(dp, -1, sizeof(dp));
	cout << f(0, 2, n);
}
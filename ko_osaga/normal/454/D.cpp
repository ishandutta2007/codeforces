#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int p[17] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
int bs[60];

int n, a[105];
int dp[105][1<<17];
int tr[105][1<<17];

void bktk(int x, int p){
	if(x == n) return;
	printf("%d ", tr[x][p]);
	bktk(x+1, p | bs[tr[x][p]]);
}

int main(){
	for(int i=2; i<60; i++){
		for(int j=0; j<17; j++){
			if(i % p[j] == 0) bs[i] |= (1<<j);
		}
	}
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	for(int i=n-1; i>=0; i--){
		for(int j=0; j<(1<<17); j++){
			dp[i][j] = 1e9;
			for(int k=1; k<60; k++){
				if(!(j & bs[k])){
					int w = dp[i+1][j|bs[k]] + abs(k - a[i]);
					if(dp[i][j] > w){
						dp[i][j] = w;
						tr[i][j] = k;
					}
				}
			}
		}
	}
	bktk(0, 0);
}
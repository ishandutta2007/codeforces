#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int n, k;
double p[22], sum[1<<20];
bool vis[1<<20];
double dp[1<<20];

double get(int b){
	if(b == 0) return 1;
	if(vis[b]) return dp[b];
	double ret = 0;
	for(int i=0; i<n; i++){
		if((b >> i) & 1){
			double t = get(b ^ (1<<i));
			t /= 1 - sum[b ^ (1<<i)];
			ret += t * p[i];
		}
	}
	vis[b] = 1;
	return dp[b] = ret;
}


double ret[22];

int main(){
	cin >> n >> k;
	int cnt = 0;
	for(int i=0; i<n; i++){
		cin >> p[i];
		if(p[i] > 1e-9){
			cnt++;
		}
	}
	k = min(k, cnt);
	for(int i=1; i<(1<<n); i++){
		for(int j=0; j<n; j++){
			if((i >>j) & 1){
				sum[i] += p[j];
			}
		}
	}
	for(int i=1; i<(1<<n); i++){
		int cnt = 0;
		for(int j=0; j<n; j++){
			if((i >> j) & 1){
				cnt++;
				if(p[j] < 1e-9) cnt = -1e9;
			}
		}
		if(cnt != k) continue;
		double gap = get(i);
		for(int j=0; j<n; j++){
			if((i >> j) & 1){
				ret[j] += gap;
			}
		}
	}
	for(int i=0; i<n; i++){
		printf("%.10f ", ret[i]);
	}
}
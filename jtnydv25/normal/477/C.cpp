#include <bits/stdc++.h>
using namespace std;

const int N = 3005, INF = 1e9;

int dp[N], dp2[N], st[N], ans[N], n, p;
char s[N], t[N];

void getNextLayer(){
	memcpy(dp2, dp, sizeof dp);
	dp2[n + 1] = INF;
	for(int i = n; i >= 1; i--){
		dp2[i] = min(dp2[i + 1], dp[i]);
		dp[i] = INF;
	}
	for(int i = 1; i <= n; i++){
		int pos = i + st[i] + p - 1;
		if(pos <= n){
			dp[i] = dp2[pos + 1] + st[i];
		}
	}
}
int main(){
	scanf("%s", s + 1);
	scanf("%s", t + 1);	
	for(int i = 1; s[i]; i++){
		dp[i] = INF;
		st[i] = INF;
		n++;
	}
	for(int i = 1; t[i]; i++) p++;
	for(int i = 1; i <= n; i++){
		if(s[i] != t[1]) continue;
		int pos = 1;
		int j = i;
		for(; j <= n && pos <= p;j++){
			if(s[j] == t[pos]){
				pos++;
				if(pos == p + 1){
					dp[i] = j - i + 1 - p;
					st[i] = dp[i];
				}
			}
		}
	}


	for(int k = 1; k * p <= n; k++){
		int mn = INF;
		for(int i = 1; i <= n; i++) mn = min(mn, dp[i]);
		for(int i = mn; i <= n - k * p; i++) ans[i] = k;
		getNextLayer();
	}

	for(int i = 0; i <= n; i++) cout << ans[i] << " ";
}
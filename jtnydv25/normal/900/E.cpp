#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define F first
#define S second

const int N = 1e5 + 10;
char s[N];
int f[N], dp[N], dp2[N], pref[N];
const int INF = 1e9;
int main(){
	int n, m;
	sd(n);
	scanf("%s", s + 1);
	for(int i = 1; i <= n; i++) pref[i] = pref[i - 1] + (s[i] == '?');
	sd(m);
	int oddA = 0, evenA = 0, oddB = 0, evenB = 0;
	for(int i = 1; i <= n; i++){
		if(i & 1){
			if(s[i] == 'a') oddA = i;
			else if(s[i] == 'b') oddB = i;
		}
		else{
			if(s[i] == 'a') evenA = i;
			else if(s[i] == 'b') evenB = i;	
		}
		int mx = 0;
		if((m & 1) == (i & 1)){
			mx = max(mx, max(oddB, evenA));
		}
		else{
			mx = max(mx, max(evenB, oddA));
		}
		dp[i] = dp[i - 1];
		dp2[i] = INF;
		if(i >= m && mx <= i - m){
			dp[i] = dp[i - m] + 1;
			if(dp[i - 1] == dp[i]){
				dp2[i] = dp2[i - 1];
			}
			dp2[i] = min(dp2[i], dp2[i - m] + pref[i] - pref[i - m]);
		}
		else dp2[i] = dp2[i - 1];
		if(dp2[i] >= INF) dp2[i] = 0;

	}
	if(dp2[n] == INF) dp2[n] = 0;
	printf("%d\n", dp2[n]);
}
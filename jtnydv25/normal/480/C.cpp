#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))

const int mod = 1e9 + 7;
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}

const int N = 5005;
int dp[N], dp2[N], dp3[N];

int n, a, b, k;
inline int getSum(int i, int j){
	if(i > j) return 0;
	return sub(dp2[j], dp2[i - 1]);
}
void getNextLayer(){
	for(int i = 1; i <= n; i++) dp2[i] = add(dp2[i - 1], dp[i]);
	memcpy(dp3, dp, sizeof dp);
	memset(dp, 0, sizeof dp);
	int mn, mx;
	for(int i = 1; i <= n; i++){
		if(i < b){
			mn = max(i - (b - i) + 1, 1);
			mx = b - 1;
		}
		else{
			mx = min(n, i + (i - b) - 1);
			mn = b + 1;
		}
		dp[i] = getSum(mn, mx);
		if(mn <= i && mx >= i) dp[i] = sub(dp[i], dp3[i]);
	}
}

int main(){
	sd(n); sd(a); sd(b); sd(k);
	for(int i = 1; i <= n; i++){
		if(i != b) dp[i] = 1;
	}

	for(int i = 1; i <= k; i++) getNextLayer();
	printf("%d\n", dp[a]);
}
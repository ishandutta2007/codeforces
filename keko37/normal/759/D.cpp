#include<iostream>

using namespace std;

const int MAXN = 5005;
const int MOD = 1000000007;

int n;
string s;
int dp[MAXN] [MAXN];
int sum[MAXN] [MAXN];

int modadd (int a, int b) {
	if (a+b>=MOD) return a+b-MOD; else return a+b;
}

int modsub (int a, int b) {
	if (a-b<0) return a-b+MOD; else return a-b;
}

int main () {
	cin >> n >> s;
	for (int i=0; i<=n; i++) {
		dp[0] [i]=1;
		sum[0] [i]=i+1;
		dp[i] [0]=1;
		sum[i] [0]=1;
	}
	for (int i=1; i<n; i++) {
		int ind=-1;
		for (int j=i-1; j>=0; j--) {
			if (s[j]==s[i]) {
				ind=j;
				break;
			}
		}
		for (int j=1; j<=n; j++) {
			dp[i] [j]=sum[i-1] [j];
			if (ind!=-1) dp[i] [j]=modsub(dp[i] [j], sum[ind] [j-1]);
			sum[i] [j]=modadd(sum[i] [j-1], dp[i] [j]);
		}
	}
	cout << dp[n-1] [n];
	return 0;
}
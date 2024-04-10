#include <iostream>
using namespace std;

int dp[12345];
char a[5432];
int n;
int main() {
	int m = 1000000007;
	cin>>n;
	for (int i = 0; i < n; i++)
		cin>>a[i];
	dp[0] = 1;
	for(int i = n-1; i >= 0; i--){	
		if(a[i] == 's'){
			int ss = 0;
			for(int j = 0; j <= n; j++){
				ss += dp[j];
				if(ss>=m) ss -= m;
				dp[j] = ss;
			}
		}else{
			for(int j = 0; j < n;j++){
				dp[j] = dp[j+1];
			}
			dp[n] = 0;
		}
	}
	cout<<dp[0];
	return 0;
}
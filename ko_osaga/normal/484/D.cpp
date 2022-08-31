#include <cstdio>  
#include <cstdlib>  
#include <vector>  
#include <algorithm>  
using namespace std;  
  
int n,a[1000005];
int ri1[1000005], ri2[1000005];
long long dp[1000005];  
  
int main(){  
	scanf("%d",&n);  
	for (int i=0; i<n; i++) {  
		scanf("%d",&a[i]);  
	}
	ri1[n-1] = ri2[n-1] = n-1;
	for(int i=n-2; i>=0; i--){
		if(a[i] > a[i+1]){
			ri1[i] = i;
		}
		else{
			ri1[i] = ri1[i+1];
		}
		if(a[i] < a[i+1]){
			ri2[i] = i;
		}
		else{
			ri2[i] = ri2[i+1];
		}
	}
	for (int i=n-2; i>=0; i--) {  
		int peak = 0;  
		if(a[i] <= a[i+1]){  
			peak = ri1[i];
			long long res = dp[peak+1] + a[peak] - a[i];  
			res = max(res,dp[peak] + a[peak-1] - a[i]);  
			dp[i] = res;  
		}  
		else{  
			peak = ri2[i];
			long long res = dp[peak+1] + a[i] - a[peak];  
			res = max(res,dp[peak] + a[i] - a[peak-1]);  
			dp[i] = res;  
		}  
	}  
	printf("%lld",dp[0]);  
}
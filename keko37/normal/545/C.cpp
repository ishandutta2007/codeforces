#include<iostream>

using namespace std;

int n;
int x[100005], h[100005];
int dp[100005], dp2[100005];
int valde[100005];

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> x[i] >> h[i];
	}
	if (n==1) {
		cout << 1;
		return 0;
	}
	dp[0]=1;
	if (x[0]+h[0]<x[1]) dp2[0]=1;
	if (x[0]+h[0]<x[1]) valde[0]=1;
	for (int i=1; i<n; i++) {
		int valli=0, valli2=0;
		if (i==n-1) {
			valde[i]=1;
		} else if (x[i]+h[i]<x[i+1]) {
			valde[i]=1;
		}
		if (x[i]-h[i]>x[i-1]) valli=1;
		if (valde[i-1] && valli && x[i]-h[i]>x[i-1]+h[i-1]) valli2=1;
		dp[i]=max(dp[i-1]+valli, dp2[i-1]+valli2);
		if (valde[i]==0) dp2[i]=0; else dp2[i]=max(dp[i-1], dp2[i-1])+1;
	}
	cout << max(dp[n-1], dp2[n-1]);
	return 0;
}
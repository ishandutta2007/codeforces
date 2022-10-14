#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 2005;

int n, sol;
int a[MAXN], dp[MAXN] [MAXN] [3], sum[MAXN] [MAXN] [3];

void calc_dp () {
	for (int i=n-1; i>=0; i--) {
		if (a[i]==1) {
			dp[i] [i] [1]=1;
			dp[i] [i] [2]=1;
		} else {
			dp[i] [i] [1]=0;
			dp[i] [i] [2]=1;
		}
		for (int j=i-1; j>=0; j--) {
			dp[i] [j] [1]=dp[i] [j+1] [1] + (a[j]==1);
			dp[i] [j] [2]=max(dp[i] [j+1] [1], dp[i] [j+1] [2]) + (a[j]==2);
		}
	}
	for (int i=0; i<n; i++) {
		sum[i] [i] [1]=(a[i]==1);
		sum[i] [i] [2]=(a[i]==2);
		for (int j=i+1; j<n; j++) {
			sum[i] [j] [1]=(a[j]==1) + sum[i] [j-1] [1];
			sum[i] [j] [2]=(a[j]==2) + sum[i] [j-1] [2];
		}
	}
}

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	calc_dp();
	for (int i=0; i<n; i++) {
		for (int j=i; j<n; j++) {
			int res=0;
			if (i>0) res+=sum[0] [i-1] [1];
			if (j!=n-1) res+=sum[j+1] [n-1] [2];
			res+=dp[j] [i] [2];
			sol=max(sol, res);
		}
	}
	cout << sol;
	return 0;
}
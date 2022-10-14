#include<iostream>
#include<cstdio>

using namespace std;

int n;
int l[1000005];
int dp[1000005];
int maxi=1000005;
int sol;

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		scanf("%d", &l[i]);
	}
	for (int i=1; i<=maxi; i++) {
		dp[i]=1;
	}
	for (int i=0; i<n; i++) {
		for (int j=2; j*l[i]<=maxi; j++) {
			dp[j*l[i]]=max(dp[j*l[i]], dp[l[i]]+1);
		}
	}
	for (int i=0; i<n; i++) {
		sol=max(sol, dp[l[i]]);
	}
	cout << sol;
	return 0;
}
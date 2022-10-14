#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

const int MAXN = 1005;
const int MOD = 1000000007;
const int OFS = 10005;

int n, sol;
int l[MAXN];
int dp[MAXN] [2*OFS];

int add (int a, int b) {
	if (a+b>=MOD) return a+b-MOD; return a+b;
}

int f (int pos, int sum) {
	if (dp[pos] [sum+OFS]!=-1) return dp[pos] [sum+OFS];
	int res=0;
	if (l[pos]==abs(sum)) res++;
	if (pos) res=add(res, add(f(pos-1, sum-l[pos]), f(pos-1, sum+l[pos])));
	dp[pos] [sum+OFS]=res;
	return res;
}

int main () {
	memset(dp, -1, sizeof dp);
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> l[i];
		sol=add(sol, f(i, 0));
	}
	cout << sol;
	return 0;
}
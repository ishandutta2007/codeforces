#include<iostream>
#include<cstring>

using namespace std;

const int MAXN = 5005;
const int MOD = 1000000007;

int n;
char l[MAXN];
int dp[MAXN] [MAXN];

int add (int a, int b) {
	a+=b;
	if (a>=MOD) return a-MOD; return a;
}

int f (int pos, int val) {
	if (pos==n) return 1;
	if (dp[pos] [val]!=-1) return dp[pos] [val];
	int res=0;
	if (pos>0 && l[pos-1]=='f') {
		res=f(pos+1, val+1);
	} else {
		res=f(pos+1, val);
		if (val>0) res=add(res, f(pos, val-1));
	}
	dp[pos] [val]=res;
	return res;
}

int main () {
	memset(dp, -1, sizeof dp);
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> l[i];
	}
	cout << f(0, 0);
	return 0;
}
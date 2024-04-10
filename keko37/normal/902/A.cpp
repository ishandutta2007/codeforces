#include<iostream>

using namespace std;

const int MAXN = 105;

int n, m, x, y;
int l[MAXN], dp[MAXN];

int main () {
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> x >> y;
		l[x]=max(l[x], y);
	}
	dp[m]=1;
	for (int i=m-1; i>=0; i--) {
		for (int j=i; j<=l[i]; j++) {
			dp[i]|=dp[j];
		}
	}
	cout << (dp[0]?"YES":"NO");
	return 0;
}
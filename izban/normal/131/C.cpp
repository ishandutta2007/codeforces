#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <queue>
#include <deque>
using namespace std;

#define sqr(x) ((x)*(x))

int n,m,t;
long long ans,c[40][40];

int main() {
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);       
        freopen("output.txt", "w", stdout);
#endif
		cin >> n >> m >> t;
		c[0][0]=1;
		for (int i=0; i<=30; i++) {
			c[0][i]=c[i][i]=1;
			for (int j=1; j<i; j++) {
				c[j][i]=c[j][i-1]+c[j-1][i-1];
			}
		}
		for (int i=1; i<t; i++) {
			if (i<=m && t-i>=4 && t-i<=n) {
				ans=ans+c[t-i][n]*c[i][m];
			}
		}
		cout << ans;
        return 0;
}
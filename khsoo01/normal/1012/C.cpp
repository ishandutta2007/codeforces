#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 5005, inf = 1e18;

ll n, a[N], dt[N][N][2], ans[N];

int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
	}
	for(int i=0;i<=n+1;i++) {
		for(int j=0;j<=(n+1)/2;j++) {
			dt[i][j][0] = dt[i][j][1] = inf;
		}
		ans[i] = inf;
	}
	dt[0][0][0] = 0;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<=i/2;j++) {
			for(int k=0;k<2;k++) {
				if(dt[i-1][j][k] == inf) continue;
				dt[i][j][0] = min(dt[i][j][0], dt[i-1][j][k]);
				ll P = (k ? min(a[i-1], a[i-2]-1) : a[i-1]), R = 0;
				if(P >= a[i]) R += P - a[i] + 1;
				if(a[i+1] >= a[i]) R += a[i+1] - a[i] + 1;
				dt[i+1][j+1][1] = min(dt[i+1][j+1][1], dt[i-1][j][k] + R);
			}
		}
	}
	for(int i=1;i<=n+1;i++) {
		for(int j=1;j<=(n+1)/2;j++) {
			ans[j] = min({ans[j], dt[i][j][0], dt[i][j][1]});
		}
	}
	for(int i=1;i<=(n+1)/2;i++) {
		printf("%lld ",ans[i]);
	}
}
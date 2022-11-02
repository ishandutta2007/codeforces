#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;

int n, dt[100005][2][2];
char a[100005];

void solve ()
{
	scanf("%s",a+1);
	n = strlen(a+1);
	for(int i=0;i<=n;i++) {
		dt[i][0][0] = dt[i][0][1] = dt[i][1][0] = dt[i][1][1] = inf;
	}
	dt[0][0][0] = 0;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<2;j++) {
			for(int k=0;k<2;k++) {
				if((j || i <= 2 || a[i-2] != a[i]) && (k || i <= 1 || a[i-1] != a[i])) {
					dt[i][k][0] = min(dt[i][k][0], dt[i-1][j][k]);
				}
				dt[i][k][1] = min(dt[i][k][1], dt[i-1][j][k] + 1);
			}
		}
	}
	printf("%d\n", min({dt[n][0][0], dt[n][0][1], dt[n][1][0], dt[n][1][1]}));
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--) solve();
}
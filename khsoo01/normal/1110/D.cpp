#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int inf = 1e9;

int n, m, c[1000005], dt[1000005][5][5];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		int T;
		scanf("%d",&T);
		c[T]++;
	}
	for(int k=0;k<=m;k++) {
		for(int i=0;i<5;i++) {
			for(int j=0;j<5;j++) {
				dt[k][i][j] = -inf;
			}
		}
	}
	dt[0][0][0] = 0;
	for(int i=1;i<=m;i++) {
		for(int j1=0;j1<5;j1++) {
			for(int j2=0;j2<5;j2++) {
				for(int j3=0;j3<3;j3++) {
					if(j1 < j3 || j2 < j3 || c[i] < j3) break;
					int A = (c[i] - j3) % 3, B = (c[i] - j3) / 3;
					dt[i][j2-j3][A] = max(dt[i][j2-j3][A], dt[i-1][j1][j2] + j3 + B);
					if(B > 0) dt[i][j2-j3][min(A+3, 4)] = max(dt[i][j2-j3][min(A+3, 4)], dt[i-1][j1][j2] + j3 + B - 1);
				}
			}
		}
	}
	int ans = 0;
	for(int i=0;i<5;i++) {
		for(int j=0;j<5;j++) {
			ans = max(ans, dt[m][i][j]);
		}
	}
	printf("%d\n",ans);
}
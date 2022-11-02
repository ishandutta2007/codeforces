#include<bits/stdc++.h>
using namespace std;

const int N = 101, M1 = 1e9+7, M2 = 1e9+9;
int n, a[N], c[N], v, dt1[N][N*N], dt2[N][N*N], ans;

int main()
{
	scanf("%d",&n);
	dt1[0][0] = 1;
	dt2[0][0] = 1;
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		if(c[a[i]] == 0) v++;
		c[a[i]]++;
		for(int j=i;j--;) {
			for(int k=0;k<=j*N;k++) {
				dt1[j+1][k+a[i]] = (dt1[j][k] + dt1[j+1][k+a[i]]) % M1;
				dt2[j+1][k+a[i]] = (dt2[j][k] + dt2[j+1][k+a[i]]) % M2;
			}
		}
	}
	if(v <= 2) {
		printf("%d\n", n);
		return 0;
	}
	for(int i=1;i<N;i++) {
		for(int j=1;j<=c[i];j++) {
			for(int k=0;k<=n-j;k++) {
				for(int l=0;l<=k*N;l++) {
					dt1[k+1][l+i] = (dt1[k+1][l+i] + M1 - dt1[k][l]) % M1;
					dt2[k+1][l+i] = (dt2[k+1][l+i] + M2 - dt2[k][l]) % M2;
				}
			}
		}
		for(int j=1;j<=c[i];j++) {
			if(dt1[j][j*i] == 0 && dt2[j][j*i] == 0) ans = max(ans, j);
			else break;
		}
		for(int j=c[i];j>=1;j--) {
			for(int k=n-j;k>=0;k--) {
				for(int l=0;l<=k*N;l++) {
					dt1[k+1][l+i] = (dt1[k+1][l+i] + dt1[k][l]) % M1;
					dt2[k+1][l+i] = (dt2[k+1][l+i] + dt2[k][l]) % M2;
				}
			}
		}
	}
	printf("%d\n",ans);
}
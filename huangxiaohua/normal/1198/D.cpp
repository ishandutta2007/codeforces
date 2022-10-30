#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,l,m,n,f[52][52][52][52],L,R,sb;

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			for(k=1;k<=n;k++){
				for(l=1;l<=n;l++){
					f[i][j][k][l]=max(k-i+1,l-j+1);
				}
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			char sb=getchar();
			if(sb=='.'){f[i][j][i][j]=0;continue;}
			if(sb=='#'){f[i][j][i][j]=1;continue;}
			j--;
		}
	}
	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++){
			for(k=1;k<=n;k++){
				for(l=1;l<=n;l++){
					L=min(n,k+i);R=min(n,l+j);
					for(m=k;m<L;m++){
						sb=f[k][l][m][R]+f[m+1][l][L][R];
						f[k][l][L][R]=(sb<f[k][l][L][R])?sb:f[k][l][L][R];
					}
					for(m=l;m<R;m++){
						sb=f[k][l][L][m]+f[k][m+1][L][R];
						f[k][l][L][R]=(sb<f[k][l][L][R])?sb:f[k][l][L][R];
					}
				}
			}
		}
	}
	printf("%d",f[1][1][n][n]);
}
#include<bits/stdc++.h>
using namespace std;
int n,a[510],num[510][510],f[510];
int main(){
	memset(num,-1,sizeof(num));
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		num[i][i]=a[i];
	}
	for (int l=1;l<=n;l++)
		for (int i=1;i+l<=n;i++){
			int j=i+l;
			for (int k=i;k<j;k++)
				if (num[i][k]!=-1&&num[i][k]==num[k+1][j]) num[i][j]=num[i][k]+1;
		}
	f[0]=0;
	for (int i=1;i<=n;i++){
		f[i]=n+1;
		for (int j=1;j<=i;j++)
			if (num[j][i]!=-1) f[i]=min(f[i],f[j-1]+1);
	}
	printf("%d\n",f[n]);
	return 0;
}
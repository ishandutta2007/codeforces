#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[505],f[2][81][6500],sum,pos[81],b[81],lim,t1,t2,res[6666],l;

int main(){
	memset(f,-2,sizeof(f));
	f[0][0][0]=0;
	scanf("%d",&n);
	lim=(n*n-n)/2;
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		if(!k){j++;sum++;}
		else{a[++m]=j;j=0;}
	}
	a[++m]=j;k=0;
	for(i=1;i<=m;i++){
		for(j=1;j<=a[i];j++){
			pos[++k]=i;
		}
	}
	for(i=1;i<=m;i++){
		for(j=1;j<=sum;j++){
			b[j]=b[j-1]+abs(pos[j]-i);
		}
		int i1=i&1,i0=1-i1;
		memset(f[i1],-2,sizeof(f[i1]));
		for(j=0;j<=sum;j++){
			for(k=j;k<=sum;k++){
				t1=b[k]-b[j];
				for(l=0;l<=lim;l++){
					if(t1+l>lim){continue;}
					f[i1][k][l+t1]=max(f[i1][k][l+t1],f[i0][j][l]+(k-j)*(sum-k+j));
				}
			}
		}
	}
	for(i=0;i<=lim;i++){
		res[i]=f[m&1][sum][i];
		if(i>0){res[i]=max(res[i-1],res[i]);}
		printf("%d ",res[i]/2);
	}
}
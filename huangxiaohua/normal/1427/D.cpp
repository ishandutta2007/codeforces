#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int i,j,k,l,r,n,a[1000][1000],res[1050][1050],rn[1050],rrr,tmp,b[1000],tmp2;
 
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[1][i]);
	}
	
	if(n==1){puts("0");return 0;}
	if(n==2){
		if(a[1][1]>a[1][2]){puts("1\n2 1 1");return 0;}
		puts("0");return 0;
	}
	
	for(i=1;;i++){
		//for(j=1;j<=n;j++){printf("%d ",a[i][j]);}puts("");
		tmp=1;
		
		for(j=1;j<=n;j++){
			if(a[i][j]!=(a[i][j-1]+1)){tmp++;}
			b[j]=tmp;
		}
		if(tmp==1){rrr=i-1;break;}
		for(j=1;j<=n;j++){
			for(k=j+1;k<=n;k++){
				if(a[i][k]==(a[i][j]-1)){l=j,r=k;break;}
			}
		}
		//printf("%d %d\n",l,r);
		for(j=l+1;j<=r;j++){
			if(b[j]==b[l]){continue;}
			b[j]=b[l]+1;
		}
		if(b[j]==b[j-1]){for(;j<=n;j++){b[j]++;}}
		
		//for(j=1;j<=n;j++){printf("b%d ",b[j]);}puts("");
		
		for(tmp=1,j=2;j<=n+1;j++,tmp++){if(b[j]!=b[j-1]){rn[i]++;res[i][rn[i]]=tmp;tmp=0;}}
		
		for(j=1,tmp=1,k=n;j<=rn[i];j++){
			k-=res[i][j];
			for(l=1;l<=res[i][j];l++,tmp++){a[i+1][l+k]=a[i][tmp];}
		}
	}
	printf("%d\n",rrr);
	for(i=1;i<=rrr;i++){
		printf("%d ",rn[i]);
		for(j=1;j<=rn[i];j++){printf("%d ",res[i][j]);
		}puts("");
	}
}
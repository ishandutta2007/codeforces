#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007

int i,j,k,n,t,a[5050],b[5050],tmp,c[5050],d[3],m,res[3]={-1};

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%1d",&a[i]);
		tmp+=a[i];
	}
	for(i=1;i<=n;i++){
		scanf("%1d",&b[i]);
		c[i]=a[i]+b[i];
		d[c[i]]++;
	}
	
	m=n>>1;
	//printf("%d %d %d\n",d[0],d[1],d[2]);
	for(i=0;i<=d[2];i++){
		for(j=0;j<=d[1];j++){
			if(i+i+j+j>n){break;}
			k=m-i-j;
			//printf("%d %d %d\n",i,j,k);
			if(k<=d[0]&&(i+i+j)==tmp){
				res[0]=d[0]-k;res[1]=d[1]-j;res[2]=d[2]-i;goto aaa;
			}
		}
	}
	
	aaa:
	if(res[0]==-1){puts("-1");return 0;}
	for(i=1;i<=n;i++){
		if(res[0]&&c[i]==0){
			res[0]--;printf("%d ",i);
		}
		if(res[1]&&c[i]==1){
			res[1]--;printf("%d ",i);
		}
		if(res[2]&&c[i]==2){
			res[2]--;printf("%d ",i);
		}
	}
}
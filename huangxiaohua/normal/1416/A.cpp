#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,t,n,a[300500],k,res[300500],tmp[300500],jg[300500];

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=300000;i++){
			jg[i]=-1;
		}
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			tmp[i]=0;res[i]=-1;
		}
		for(i=1;i<=n;i++){
			k=a[i];
			jg[k]=max(jg[k],i-tmp[k]);
			tmp[k]=i;
		}
		for(i=1;i<=n;i++){
			if(jg[i]==-1){continue;}
			jg[i]=max(jg[i],n+1-tmp[i]);
		}
		for(i=1;i<=300000;i++){
			//printf("%d %d\n",i,jg[i]);
			for(j=jg[i];j<=n;j++){
				if(res[j]>0||jg[i]==-1){break;}
				res[j]=i;
			}
		}
		for(i=1;i<=n;i++){
			printf("%d ",res[i]);
		}puts("");
	}
}
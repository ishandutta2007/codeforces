#include<bits/stdc++.h>
using namespace std;
 
int t,n,a[10500],res[10500],i,j,tmp,b1[10500],b2[10500],jj,jjj;
 
int check(){
	for(int ii=n;ii>=2;ii--){
		if(res[ii]<res[ii-1]){return 1;}
	}
	return 0;
}
 
int main(){
	scanf("%d",&t);
	while(t--){
		memset(a,0,sizeof(a));
		memset(res,-1,sizeof(res));
		memset(b1,0,sizeof(b1));
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&res[i]);
			a[res[i]]++;
		}
		while(check()){
			for(i=0;i<=n;i++){
				if(a[i]==0){tmp=i;j=tmp;break;}
			}
			while(res[j]==j||j==0){
				j++;
			}
			a[res[j]]--;a[tmp]++;b1[0]++;b1[b1[0]]=j;res[j]=tmp;
		}
		
		printf("%d\n",b1[0]);
		for(i=1;i<=b1[0];i++){printf("%d ",b1[i]);}
		puts("");
		
		
	}
}
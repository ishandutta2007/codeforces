#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int i,j,n,t,res,k,rnk[200500],a[200500];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(rnk,0,n*4+20);
		
		scanf("%*d");
		
		res=1;a[1]=1;rnk[1]=1;j=11451419;
		
		for(i=2;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]<j){
				if(!rnk[res]){res++;rnk[res+1]++;rnk[res]--;j=11451419;}
				else{rnk[res]--;rnk[res+1]++;}
			}
			else{
				rnk[res+1]++;
			}
			j=a[i];
			//printf("%d %d\n",i,res);
		}
		printf("%d\n",res+(rnk[res+1]>0)-1);
	}
}
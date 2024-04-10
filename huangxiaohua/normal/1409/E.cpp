#include <bits/stdc++.h> 
using namespace std;

int a[200500],t,i,j,res=0,b[200500],c[200500],k,n,tmp;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);res=0,tmp=0;
		memset(b,0,4*n+10);
		memset(c,0,4*n+10);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(i=1;i<=n;i++){
			scanf("%*d");
		}
		sort(a+1,a+n+1);
		if(a[n]-a[1]<=2*k){printf("%d\n",n);continue;}
		
		for(i=1,j=1;i<=n;i++){
			for(;;j++){
				if(j==n+1||a[j]-a[i]>k){b[i]=j-i;break;}
			}
		}
		for(i=n;i>=1;i--){
			tmp=max(tmp,b[i]);
			c[i]=tmp;
		}
		for(i=1;i<=n;i++){
			//printf("%d %d %d %d\n",i,a[i],b[i],c[i]);
			res=max(res,b[i]+c[i+b[i]]);
		}
		printf("%d\n",res);
 
	}
}
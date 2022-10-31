#include<bits/stdc++.h>
using namespace std;
 
int i,n,t,q,x,y;
long long res,a[300500];
 
int main(){
	scanf("%d",&t);
	
	while(t--){
		scanf("%d%d",&n,&q);res=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		a[n+1]=0;
		for(i=1;i<=n;i++){
			if(a[i]-a[i+1]>0){res+=a[i]-a[i+1];
			}
		}
		printf("%lld\n",res);
		while(q--){
			scanf("%d%d",&x,&y);
			if(x==y){printf("%lld\n",res);continue;}
			if(x>y){swap(x,y);}
			
			if((y-x)==1){
				if(x>1&&a[x-1]-a[x]>0){res-=(a[x-1]-a[x]);}
				if(a[x]-a[x+1]>0){res-=(a[x]-a[x+1]);}
				if(a[y]-a[y+1]>0){res-=(a[y]-a[y+1]);}
				swap(a[x],a[y]);
				if(x>1&&a[x-1]-a[x]>0){res+=(a[x-1]-a[x]);}
				if(a[x]-a[x+1]>0){res+=(a[x]-a[x+1]);}
				if(a[y]-a[y+1]>0){res+=(a[y]-a[y+1]);}	
			}
			
			else{
			if(x>1&&a[x-1]-a[x]>0){res-=(a[x-1]-a[x]);}
			if(y>1&&a[y-1]-a[y]>0){res-=(a[y-1]-a[y]);}
			if(a[x]-a[x+1]>0){res-=(a[x]-a[x+1]);}
			if(a[y]-a[y+1]>0){res-=(a[y]-a[y+1]);}
			swap(a[x],a[y]);
			if(x>1&&a[x-1]-a[x]>0){res+=(a[x-1]-a[x]);}
			if(y>1&&a[y-1]-a[y]>0){res+=(a[y-1]-a[y]);}
			if(a[x]-a[x+1]>0){res+=(a[x]-a[x+1]);}
			if(a[y]-a[y+1]>0){res+=(a[y]-a[y+1]);}
			}
			
			printf("%lld\n",res);
		}
		
	}
}
#include<bits/stdc++.h>
using namespace std;

int w,n,x,y,res,t,i,j,tmp,mx,mn;

int main(){
	scanf("%d",&n);
	while(n--){
		res=0;w=0;mx=-1;mn=114514;
		scanf("%d%d",&t,&x);
		for(i=1;i<=t;i++){
			scanf("%d",&tmp);
			res+=tmp;
			if(tmp%x!=0){w=1;mx=max(i,mx);mn=min(i,mn);}
		}
		if(w==0){puts("-1");continue;}
		if(res%x==0){printf("%d\n",t-min(t+1-mx,mn));continue;}
		else{printf("%d\n",t);}
	}
}
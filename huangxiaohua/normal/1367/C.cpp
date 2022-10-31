#include <bits/stdc++.h>
using namespace std;
 
int n,t,i,m,res,tmp,sb,one;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d\n",&n,&m);
		res=tmp=0;one=1;
		for(i=1;i<=n;i++){
			scanf("%1d",&sb);
			if(sb==0){tmp++;}
			if(sb==1){
				tmp-=one*m;
				if(tmp<=0){goto aaa;}
				res+=tmp/(m+1)+1;
				if(tmp%(m+1)==0){res--;}
				aaa:if(one==1){one=2;}
				tmp=0;
			}
		}
		one--;
		if(one==0){
			res++;
			tmp-=m+1;
			if(tmp<=0){printf("%d\n",res);continue;}
			res+=tmp/(m+1)+1;
			if(tmp%(m+1)==0){res--;}
			printf("%d\n",res);continue;
		}
		tmp-=one*m;
		if(tmp<=0){goto bbb;}
		res+=tmp/(m+1)+1;
		if(tmp%(m+1)==0){res--;}
		bbb:printf("%d\n",res);
	}
}
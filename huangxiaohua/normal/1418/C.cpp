#include <bits/stdc++.h>
using namespace std;

int i,j,a,b,res,n,sb,t,k;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	scanf("%d",&t);
	while(t--){
		a=res=0;
		a=1;
		scanf("%d",&n);
		
		if(n==114514){puts("");return 0;}
		
		for(i=1;i<=n;i++){
			scanf("%d",&k);
			if(k){
				b++;
			}
			else{
				if(a){
					if(!b){a=0;continue;
					}
					res++;res+=(b-1)/3;a=b=0;
				}
				else{
					res+=b/3;b=0;
				}
			}
		}
		
		if(a){
			if(!b){
			}
			res++;res+=(b-1)/3;a=b=0;
		}
		else{
			res+=b/3;b=0;
		}
		
		printf("%d\n",res);
	}
}
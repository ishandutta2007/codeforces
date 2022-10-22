#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int tot,a,b,c,now,ans;
	while(scanf("%d%d%d%d",&tot,&a,&b,&c)!=EOF){
		now=1;ans=0;
		for(int i=1;i<tot;i++){
			if(now==1){
				if(a<b){
					ans+=a;now=2;
				}
				else{
					ans+=b;now=3;
				}
			}
			else if(now==2){
				if(a<c){
					ans+=a;now=1;
				}
				else{
					ans+=c;now=3;
				}
			}
			else{
				if(b<c){
					ans+=b;now=1;
				}
				else{
					ans+=c;now=2;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
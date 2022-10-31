#include<bits/stdc++.h>
using namespace std;
 
int i,n,t,x,l,r;
char sb[105500],res[105500];
int main(){
	scanf("%d",&t);getchar();
	while(t--){
		gets(sb+1);
		n=strlen(sb+1);
		scanf("%d",&x);getchar();
		for(i=0;i<=n;i++){
			res[i]='x';
		}res[n+1]=0;
		
		for(i=1;i<=n;i++){
			l=i-x;r=i+x;
			if((l<1)&&(r>n)){
				if(sb[i]==49){puts("-1");goto aaa;}
				continue;
			}
			if((l<1)&&(r<=n)){
				if(sb[i]==48&&res[r]==49){puts("-1");goto aaa;}
				if(sb[i]==49&&res[r]==48){puts("-1");goto aaa;}
				if(sb[i]==48&&res[r]!=49){res[r]=48;continue;}
				if(sb[i]==49&&res[r]!=48){res[r]=49;continue;}
			}
			if((l>=1)&&(r>n)){
				if(sb[i]==48&&res[l]==49){puts("-1");goto aaa;}
				if(sb[i]==49&&res[l]==48){puts("-1");goto aaa;}
				if(sb[i]==48&&res[l]!=49){res[l]=48;continue;}
				if(sb[i]==49&&res[l]!=48){res[l]=49;continue;}
			}
		}
 
		for(i=1;i<=n;i++){
			l=i-x;r=i+x;
			if((l>=1)&&(r<=n)){
				if(sb[i]==48){
					if(res[l]==49||res[r]==49){puts("-1");goto aaa;}
					res[l]=res[r]=48;continue;
				}
			}
		}
 
		
		for(i=1;i<=n;i++){
			if(res[i]=='x'){res[i]=49;}
		}
		
		for(i=1;i<=n;i++){
			l=i-x;r=i+x;
			if((l>=1)&&(r<=n)){
				if(sb[i]==49){
					if(res[l]==48&&res[r]==48){puts("-1");goto aaa;}
				}
			}
		}
		puts(res+1);
		aaa:;
	}
	
}
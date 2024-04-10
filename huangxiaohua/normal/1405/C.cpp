#include<bits/stdc++.h>
using namespace std;

int i,j,n,k,cur,t,one,zero;
char sb[300500];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d\n",&n,&k);
		gets(sb+1);
		
		for(i=1;i<=k;i++){
			cur=-1;
			for(j=i;j<=n;j+=k){
				//printf("%d %d %d %c\n",i,j,cur,sb[i]);
				if(sb[j]=='?'){continue;}
				if(sb[j]=='1'){
					if(cur==0){puts("NO");goto aaa;}
					if(cur==-1){cur=1;continue;}
				}
				if(sb[j]=='0'){
					if(cur==1){puts("NO");goto aaa;}
					if(cur==-1){cur=0;continue;}
				}
			}
			if(cur==1){
				for(j=i;j<=n;j+=k){
					sb[j]='1';
				}
			}
			if(cur==0){
				for(j=i;j<=n;j+=k){
					sb[j]='0';
				}
			}
		}
		one=zero=0;
		for(i=1;i<=k;i++){
			if(sb[i]=='1'){
				one++;
			}
				if(sb[i]=='0'){
				zero++;
			}
		}
		if(one>(k/2)||zero>(k/2)){
			puts("NO");
		}
		else{
			puts("YES");
		}
		aaa:;
	}
}
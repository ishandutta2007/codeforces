#include<bits/stdc++.h>
using namespace std;
#define LL long long int
 
int n,i,t,sb[1100][2],j,sum,tmp;
  
int main(){
    scanf("%lld",&n);
    while(n--){
    	scanf("%d",&t);
    	
    	for(i=0;i<=1023;i++){sb[i][1]=sb[i][0]=0;}
    	for(i=1;i<=t;i++){
    		scanf("%d",&tmp);
    		sb[tmp][0]=1;
		}
		if(t%2==1){puts("-1");continue;}
		for(i=1;i<=1023;i++){
			sum=0;
			for(j=0;j<=1023;j++){
				sb[j][1]=0;
			}
			for(j=0;j<=1023;j++){
				if(sb[j][0]==1&&sb[j^i][0]==0&&sb[j][1]==0){
					sum=0;break;
				}
				if(sb[j][0]==1&&sb[j^i][0]==1&&sb[j][1]==0){
					sb[j][1]=sb[j^i][1]=1;sum+=2;
				}
			}
			if(sum==t){printf("%d\n",i);goto aaa;
			}
		}
		puts("-1");
		aaa:continue;
	}
}
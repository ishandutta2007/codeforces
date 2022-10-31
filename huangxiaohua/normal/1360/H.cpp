#include<bits/stdc++.h>
using namespace std;
#define LL long long int
 
char sb[105];
LL s[105],ans[105],i,t,j,k,m,n,a,b,sum,A,B,C=0,M,mid;
 
int main() {
    scanf("%lld",&t);
    for(k=1;k<=t;k++){
    	scanf("%lld%lld",&m,&n);
    	for(i=1;i<=101;i++){
    		s[i]=0;
		}
    	for(i=1;i<=m;i++){
    		scanf("%s",&sb);
    		for(j=0;j<=n-1;j++){
    			s[i]*=2;s[i]+=(sb[j]-48);
			}
		}
		sort(s+1,s+1+m);
		M=pow(2,n-1);A=M-100;B=M+100;
		for(i=max(A,C);i<=min(B,M*2);i++){
			a=b=0;
			for(j=1;j<=m;j++){
				if(s[j]==i){a=114514;break;}
				if(s[j]>i){b++;}
				if(s[j]<i){a++;}
			}
			sum=(i+1-a)-(M*2-i-b);
			//printf("%lld\n",sum);
			if(sum==0||sum==-1){mid=i;break;
			}
		}
		for(i=n;i>=1;i--){//printf("%lld\n",mid);
			(mid%2==1)?ans[i]=1:ans[i]=0;mid/=2;
		}
		for(i=1;i<=n;i++){
			printf("%lld",ans[i]);
		}printf("\n");
	}
}
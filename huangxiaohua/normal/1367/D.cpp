#include <bits/stdc++.h>
using namespace std;
 
int n,t,m,i,j,k,sb[27],res[55],b[55][2],sum,tsum;
 
char tmp[50];
int main(){
	scanf("%d\n",&t);
	while(t--){
	    
		memset(sb,0,sizeof(sb));
		memset(b,0,sizeof(b));
		memset(res,0,sizeof(res));
		sum=tsum=0;
		
		gets(tmp);
		n=strlen(tmp);
		
		for(i=1;i<=n;i++){
			sb[tmp[i-1]-'a'+1]++;
		}
		scanf("%d",&m);
		for(i=1;i<=m;i++){
			scanf("%d",&b[i][0]);
		}getchar();
		
		j=26;
		
		while(tsum!=m){
			for(i=1;i<=m;i++){
				if(b[i][0]==0&&b[i][1]==0){b[i][1]=1;sum++;tsum++;}
			}
			while(sb[j]<sum){j--;}
			sb[j]-=sum;
			for(i=1;i<=m;i++){
				if(b[i][1]==1){res[i]=j;
					for(k=1;k<=m;k++){
						b[i][1]=2;
						if(b[k][1]==0){b[k][0]-=abs(k-i);}
					}
				}
			}
			sum=0;
			j--;
		}
		
		for(i=1;i<=m;i++){
				printf("%c",res[i]+'a'-1);
			}puts("");
	}
}
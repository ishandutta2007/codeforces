#include <bits/stdc++.h>
using namespace std;
 
int gcd(int a,int b){
	if(a%b==0){return b;}
	return gcd(b,a%b);
}
 
int n,t,m,i,j,k,sb[27],res,tmp1,tmp2;
 
char tmp[2050];
int main(){
	scanf("%d\n",&t);
	while(t--){
		memset(sb,0,sizeof(sb));
		res=0;
		scanf("%d%d\n",&n,&m);
		gets(tmp);
		
		for(i=1;i<=n;i++){
			sb[tmp[i-1]-'a'+1]++;
		}
		
		/*for(i=1;i<=26;i++){
			printf("%d ",sb[i]);
		}puts("");*/
		
		for(i=1;i<=n;i++){
			if(m%i==0){res=i;}
		}
		for(i=res;i<=n;i++){
			tmp1=tmp2=0;
			tmp1=i/gcd(i,m);
			for(j=1;j<=26;j++){
				tmp2+=sb[j]/tmp1;
			}
			if(tmp2>=gcd(i,m)){res=i;
			}
		}printf("%d\n",res);
	}
}
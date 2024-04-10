#include<bits/stdc++.h>
using namespace std;

int i,n,t,k,j,res,sb[30][30],t1,t2,yes,yes2;
char a[200500],b[200500],c,tmp;
int main(){
	scanf("%d\n",&t);
	while(t--){
		scanf("%d\n",&n);
		gets(a+1);
		gets(b+1);
		memset(sb,0,sizeof(sb));
		res=0;c='a';
		for(i=1;i<=n;i++){
			t1=a[i]-'a'+1;
			t2=b[i]-'a'+1;
			sb[t1][t2]=1;
			if(a[i]>b[i]){
				puts("-1");goto aaa;
			}
		}
		
		while(strcmp(a+1,b+1)){
			tmp='z';yes2=0;
			
			/*for(i=1;i<=20;i++){
				for(j=1;j<=20;j++){
					printf("%d ",sb[i][j]);
				}puts("");
			}*/
			
			for(i=1;i<=n;i++){
				if(a[i]==c&&b[i]!=c){yes2=1;tmp=min(tmp,b[i]);}
			}
			for(j=c-'a'+2;j<=tmp-'a'+1;j++){
				yes=0;
				for(k=1;k<=20;k++){
					if(sb[c-'a'+1][k]+sb[j][k]==2){yes=1;break;}
				}
				if(yes==1){break;}
			}
			if(yes2==0){c++;continue;}
			if(j==tmp-'a'+2){j--;}
			for(i=1;i<=n;i++){
				if(a[i]==c&&b[i]!=c){a[i]=j+'a'-1;}
			}
			for(i=1;i<=20;i++){
				if(i<=j){continue;}
				sb[j][i]=max(max(0,sb[c-'a'+1][i]),sb[j][i]);
			}
			c++;res++;
			
			//puts(a+1);
		}
		printf("%d\n",res);
		aaa:continue;
	}
}
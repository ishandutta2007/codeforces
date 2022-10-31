#include<bits/stdc++.h>
using namespace std;

int k,n,i,t,a[200500],an,tmp,res;
char sb[200500];

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d\n",&n);
		an=-1;tmp=res=0;
		memset(a,0,n*4+50);
		for(i=1;i<=n;i++){
			scanf("%c",&sb[i]);
			if(sb[i]!=sb[i-1]){
				an++;a[an]=tmp;tmp=1;
			}
			else{
				tmp++;
			}
		}getchar();
		an++;a[an]=tmp;
		if(an==1){
			res++;a[1]--;
			if(a[1]>=3){res+=a[1]/3;}
			printf("%d\n",res);goto aaa;
		}
		if(sb[1]==sb[n]&&an>1){a[1]+=a[an];an--;}
		for(i=1;i<=an;i++){
			if(a[i]>=3){res+=a[i]/3;}
		}
		printf("%d\n",res);
		aaa:;
	}
	
}
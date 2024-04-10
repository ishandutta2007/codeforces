#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,n,a[100500],an,res,tmp,ls,kk,win;
char sb;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);getchar();
		an=res=ls=tmp=kk=win=0;
		
		for(i=1;i<=n;i++){
			scanf("%c",&sb);
			if(sb=='W'){
				if(!win){res++;win=1;tmp=1;kk=0;continue;
				}
				if(tmp){res+=2;}
				else{an++;a[an]=kk;kk=0;res++;tmp=1;}
			}
			else{
				tmp=0;kk++;ls++;
			}
		}getchar();
		
		sort(a+1,a+an+1);
		//for(i=1;i<=an;i++){printf("%d ",a[i]);}puts("");
		res+=min(ls,k)*2;
		if(!win&&(min(ls,k))){res--;}
		for(i=1;i<=an;i++){
			if(k>=a[i]){k-=a[i];res++;}else{break;}
		}
		printf("%d\n",res);
	}
}
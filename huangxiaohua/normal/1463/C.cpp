#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,n,t,j,res,r,x,y,tme,cur,cur2,tmp;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		r=cur=res=tme=cur2=tmp=0;
		for(i=1;i<=n;i++){
			scanf("%d%d",&x,&y);
			if(n==1){res=1;break;}
			if(i==1){tmp=r=y;tme=x;continue;}
			if(r>=cur){cur2=min(r,cur+(x-tme));}
			if(r<=cur){cur2=max(r,cur-(x-tme));}
			if(cur<=tmp&&tmp<=cur2){res++;goto aaa;}
			if(cur>=tmp&&tmp>=cur2){res++;}
			aaa:
			tmp=y;
			tme=x;
			cur=cur2;
			if(r==cur&&i==n){res++;break;}
			if(i==n&&cur<=tmp&&tmp<=r){res++;break;}
			if(i==n&&cur>=tmp&&tmp>=r){res++;break;}
			if(r==cur){r=y;}
		}
		printf("%d\n",res);
	}
}
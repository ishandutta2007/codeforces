#include<bits/stdc++.h>
const int MAXN=30+5;
int n,m,r;
int s[MAXN+5],b[MAXN+5];
int mins=1000,maxb=1;
int main(){
	scanf("%d%d%d",&n,&m,&r);
	for(int i=1;i<=n;++i){
		scanf("%d",&s[i]);
		mins=std::min(mins,s[i]);
	}
	for(int i=1;i<=m;++i){
		scanf("%d",&b[i]);
		maxb=std::max(maxb,b[i]);
	}
	if(mins>=maxb){
		printf("%d\n",r);
	}else{
		printf("%d\n",r%mins+r/mins*maxb);
	}
	return 0;
}
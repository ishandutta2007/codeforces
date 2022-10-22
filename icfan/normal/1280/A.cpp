#include<bits/stdc++.h>
const int N=1e6+5,mo=1e9+7;
int T,x,i,j,l1,l2;
char c[N];
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d%s",&x,c+1);
		l1=l2=strlen(c+1);
		for(i=1; i<=x; ++i) {
			int dl=l1-i;
			l1=(l1+1ll*(dl+mo)*(c[i]-'0'-1))%mo;
			if(l2<=x+1)for(j=0; j<(c[i]-'0'-1)*dl && l2<x+1; ++j)++l2,c[l2]=c[l2-dl];
		}
		printf("%d\n",l1);
	}
	return 0;
}
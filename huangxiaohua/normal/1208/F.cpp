#include <bits/stdc++.h>
using namespace std;

#define b(x) (1<<((x)-1))
int i,j,k,n,m,t,a[1005000],res,tmp;

struct sb{
	int a,b;
}s[2205000];

void upd(int x,int y){
	if(s[x].a<y){s[x].b=s[x].a;s[x].a=y;return;}
	if(s[x].b<y&&y!=s[x].a){s[x].b=y;return;}
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		upd(a[i],i);
	}
	for(i=b(22)-1;i>=0;i--){
		for(j=1;j<=21;j++){
			if(b(j)&i){continue;}
			upd(i,s[i^b(j)].a);
			upd(i,s[i^b(j)].b);
		}
	}
	for(i=1;i<=n-2;i++){
		tmp=0;
		for(j=21;j>=1;j--){
			if(!(a[i]&b(j))){
				if(s[tmp|b(j)].b>i){tmp|=b(j);}
			}
		}
		res=max(res,tmp|a[i]);
	}
	printf("%d",res);
}
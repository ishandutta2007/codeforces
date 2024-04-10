#include <bits/stdc++.h>
using namespace std;


#define M 1000000007

int i,j,k,n,m,t,l[1005000],r[1005000],f[1005000],ll,rr,l1,r1;
long long res;
void add(int x){for(;x<=n+5;x+=(-x&x)){f[x]++;}}
int get(int x,int y=0){for(;x;x-=(-x&x)){y+=f[x];}return y+f[0];}
int main(){
	scanf("%d%d",&n,&m);rr=n+1;
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		if(!l[k]){l[k]=r[k]=i;}
		else{r[k]=i;}
	}
	for(i=0;i<=m;i++){
		if(i==0||!l[i]||l[i]>ll){
			ll=max(ll,r[i]);l1=i;
			if(!ll){f[0]++;}else{add(ll);}
		}
		else{break;}
	}
	if(l1==m){
		printf("%lld",(1ll*m*m+m)/2);return 0;
	}
	for(i=m+1;i>=2;i--){
		if(i==m+1||!r[i]||r[i]<rr){
			if(l[i]){rr=min(rr,l[i]);}
			res+=get(rr-1);
		}
		else{break;}
	}
	printf("%lld",res);
}
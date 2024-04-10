#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)-1))
int i,j,k,n,m,t,f[1005000],it,nmsl;

void add(int x,int y){
	for(;x<=1000000;x+=(-x&x))f[x]+=y;
}

int main(){
	cin.tie(0);
	scanf("%d%d",&n,&t);
	for(i=1;i<=n;i++){
		scanf("%d",&k);add(k,1);
	}
	while(t--){
		scanf("%d",&k);
		if(k>0)add(k,1);
		else{
			it=0;k=-k;nmsl=0;
			for(i=20;i>=1;i--){
				j=it+b(i);
				if(j<=1000000&&f[j]+nmsl<k){it=j;nmsl+=f[j];}
			}
			add(it+1,-1);
		}
	}
	for(i=1;i<=1000000;i++){
		if(f[i])return printf("%d",i),0;
	}
	puts("0");
}
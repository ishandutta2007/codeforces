#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,sb,a[100500],b[100500],pos[100500],res;

void add(int x){
	for(;x;x-=(-x&x)){a[x]++;}
}

int get(int x,int y=0){
	for(;x<=n;x+=(-x&x)){y+=a[x];}return y;
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		pos[k]=i;
	}
	for(i=1;i<=n;i++){
		k=get(pos[b[i]]);
		if(k){res++;}
		add(pos[b[i]]);
	}
	printf("%d",res);
}
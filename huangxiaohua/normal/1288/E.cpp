#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[600500],r1[300500],r2[300500],pos[300500],it,x;

void add(int x,int y){
	for(;x;x-=(-x&x)){a[x]+=y;}
}
int get(int x,int y=0){
	for(;x<=600000;x+=(-x&x)){y+=a[x];}return y;
}

int main(){
	scanf("%d%d",&n,&t);it=n;
	for(i=1;i<=n;i++){
		pos[i]=n+1-i;
		r1[i]=r2[i]=i;
		add(i,1);
	}
	while(t--){
		scanf("%d",&x);
		r1[x]=1;r2[x]=max(r2[x],get(pos[x]));
		add(pos[x],-1);pos[x]=++it;add(it,1);
	}
	for(i=1;i<=n;i++){
		r2[i]=max(r2[i],get(pos[i]));
		printf("%d %d\n",r1[i],r2[i]);
	}
}
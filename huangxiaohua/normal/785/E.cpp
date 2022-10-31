#include <bits/stdc++.h>
using namespace std;

const int m=2e3;
int i,j,k,n,t,f[105][m*105],a[m*105],siz[m];
long long res;

void b(int x,int i,int z){for(int y=i;y;y-=(-y&y)){f[x][y]+=z;}}
int get(int x,int y,int z=0){for(;y<=n;y+=(-y&y)){z+=f[x][y];}return z;}
int get2(int x){
	int i,j=(x-1)/m,res=0;
	for(i=0;i<j;i++){res+=get(i,a[x]+1);}
	for(i=j*m+1;i<x;i++){res+=(a[i]>a[x]);}
	for(i=x+1;i<=min(n,(j+1)*m);i++){res+=(a[i]<a[x]);}
	for(i=j+1;i<=(n-1)/m;i++){res+=siz[i]-get(i,a[x]+1);}
	return res;
}

int main(){
	scanf("%d%d",&n,&t);
	for(i=1;i<=n;i++){a[i]=i;b((i-1)/m,i,1);siz[(i-1)/m]++;}
	while(t--){
		scanf("%d%d",&j,&k);
		if(j>k){swap(j,k);}
		res-=get2(j)+get2(k);
		if(a[j]>a[k]){res++;}
		b((j-1)/m,a[j],-1);b((k-1)/m,a[j],1);b((k-1)/m,a[k],-1);b((j-1)/m,a[k],1);
		swap(a[j],a[k]);
		res+=get2(k)+get2(j);
		if(a[j]>a[k]){res--;}
		printf("%lld\n",res);
	}
}
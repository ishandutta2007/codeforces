#include<bits/stdc++.h>
using namespace std;
const int M=1e6+9;
int _f[M<<1],_vis[M<<1],*f=_f+M,*vis=_vis+M;
int n,pos=0,rk=0;
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
int main(){
	for(int i=-1e6;i<=1e6;++i)f[i]=i;
	scanf("%d",&n);
	for(int i=1,x;i<=n;++i){
		scanf("%d",&x);
		x=find(x);
		vis[x]=1;
		f[x]=f[x-1];
		if(x==pos)rk++;
		if(x<pos){
			rk++;
			if(rk+pos==1)pos-=!vis[pos];
			else if(rk+pos>1)pos--,rk--;
		}
		printf("%d\n",pos+i-rk);
	}
	return 0;
}
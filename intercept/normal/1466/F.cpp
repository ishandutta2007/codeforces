#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int M=1e6+9;
int n,m,ans;
int f[M],sum[M];
vector<int>s;
int kpow(int a,int b,int rex=1){
	for(;b;b>>=1){
		if(b&1)rex=1ll*rex*a%mod;
		a=1ll*a*a%mod;
	}
	return rex;
}
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
void add(int x,int y,int id){
	int fx=find(x),fy=find(y);
	if(fx!=fy){
		if(sum[fx]<sum[fy])swap(fx,fy);
		f[fy]=fx;
		ans++;
		s.push_back(id);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<=m;++i)f[i]=i,sum[i]=0;
	for(int i=1,o,x,y;i<=n;++i){
		scanf("%d%d",&o,&x);
		if(o==1)add(0,x,i);
		if(o==2){
			scanf("%d",&y);
			add(x,y,i);
		}
	}
	printf("%d %d\n",kpow(2,ans),ans);
	for(auto o : s)printf("%d ",o);
	return 0;
}
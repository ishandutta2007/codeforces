#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int T;
int w[N],ne[N],la[N],t;
ll len[N];
ll f[N][2];
int n,k;
void link(int x,int y,ll z){
	w[++t]=y;
	ne[t]=la[x];
	la[x]=t;
	len[t]=z;
}
priority_queue<ll> q;
ll sum=0;
void clear(){
	while (q.size())q.pop();
	sum=0;
}
void pop1(){
	sum-=-q.top();
	q.pop();
}
void add(ll v){
	q.push(-v);
	sum+=v;
	if (q.size()>k)pop1();
}
void dfs(int x,int fa){
	for (int y=la[x];y;y=ne[y]){
		int z=w[y];
		if (z==fa)continue;
		dfs(z,x);
	}
	for (int y=la[x];y;y=ne[y]){
		int z=w[y];
		if (z==fa)continue;
		ll a=f[z][0]+len[y],b=max(f[z][1],f[z][0]);
		a=max(a,b);
		add(a-b);
		f[x][1]+=b;
	}
	f[x][1]+=sum;
	if (q.size()==k)f[x][0]=f[x][1]+q.top();
	else f[x][0]=f[x][1];
	clear();
}
int main(){
	for (cin>>T;T--;){
		t=0;
		scanf("%d%d",&n,&k);
		for (int i=1;i<=n;i++)la[i]=f[i][0]=f[i][1]=0;
		for (int i=1;i<n;i++){
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			link(x,y,z);
			link(y,x,z);
		}
		dfs(1,0);
		printf("%lld\n",f[1][1]);
	}
}
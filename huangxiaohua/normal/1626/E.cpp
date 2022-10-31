#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[300500],f[300500],c[300500],g[300500];

vector<int> v[300500];

void dfs(int x,int fa){
	for(auto i:v[x]){
		if(i==fa)continue;
		dfs(i,x);
		if(a[i]>=2){
			f[x]|=f[i];
		}
		a[x]+=a[i];
	}
}

void dfs2(int x,int fa,int a1,int f1){
	//printf("nmsl%d %d %d %d\n",x,fa,a1,f1);
	if(a1>=2)f[x]|=f1;
	else f1=0;
	int a0=a1+c[x],f0=f1+g[x];
	
	for(auto i:v[x]){
		if(i==fa)continue;
		a0+=a[i];
		if(a[i]>=2)f0+=f[i];
	}
	for(auto i:v[x]){
		if(i==fa)continue;
		a0-=a[i];f0-=f[i]*(a[i]>=2);
		dfs2(i,x,a0,f0>0);
		a0+=a[i];f0+=f[i]*(a[i]>=2);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		c[i]=a[i];
	}
	for(i=1;i<n;i++){
		cin>>j>>k;
		v[j].push_back(k);
		v[k].push_back(j);
	}
	for(i=1;i<=n;i++){
		if(a[i]){
			for(auto j:v[i])f[j]=g[j]=1;
			f[i]=g[i]=1;
		}
	}
	dfs(1,0);
	dfs2(1,0,0,0);
	
	for(i=1;i<=n;i++)cout<<(f[i]>0)<<' ';
}
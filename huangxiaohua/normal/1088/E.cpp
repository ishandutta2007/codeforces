#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)-1))

int i,j,k,n,m,t;
ll a[500500],f[500500],s[500500],mx=-1e18,res;

vector<int> v[500500];

void dfs(int x,int fa){
	s[x]=a[x];
	for(auto i:v[x]){
		if(i==fa)continue;
		dfs(i,x);
		s[x]+=s[i];
		f[x]+=min(0ll,f[i]);
	}
	mx=max(mx,s[x]-f[x]);
	f[x]=min(s[x],f[x]);
}

void dfs1(int x,int fa){
	s[x]=a[x];
	for(auto i:v[x]){
		if(i==fa)continue;
		dfs1(i,x);
		s[x]+=s[i];
		f[x]+=min(0ll,f[i]);
	}
	if((s[x]-f[x])==mx){
		s[x]=f[x]=0;res++;
	}
	f[x]=min(s[x],f[x]);
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(i=1;i<n;i++){
		scanf("%d%d",&j,&k);
		v[j].push_back(k);
		v[k].push_back(j);
	}
	dfs(1,0);
	memset(f,0,sizeof(f));
	dfs1(1,0);
	printf("%lld %lld",mx*res,res);
}
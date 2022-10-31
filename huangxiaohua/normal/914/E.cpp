#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)-1))

int i,j,k,n,m,t,it,siz[200500],num,rt,cur;
char s[200500];
bool del[200500];

ll g[2005000],f[2005000],h[2005000];
vector<int> v[200500];

void dfs(int x,int fa){
	siz[x]=1;num++;
	for(auto i:v[x]){
		if(i==fa||del[i])continue;
		dfs(i,x);
		siz[x]+=siz[i];
	}
}

void dfs2(int x,int fa){
	bool y=1;
	for(auto i:v[x]){
		if(i==fa||del[i])continue;
		if(siz[i]*2>num)y=0;
		dfs2(i,x);
	}
	if(y&& ((num-siz[x])*2)<=num )rt=x;
}

void dfs3(int x,int fa){
	cur^=b(s[x]);
	g[cur]++;
	for(auto i:v[x]){
		if(i==fa||del[i])continue;
		dfs3(i,x);
	}
	cur^=b(s[x]);
}

void dfs4(int x,int fa){
	cur^=b(s[x]);
	g[cur]--;
	for(auto i:v[x]){
		if(i==fa||del[i])continue;
		dfs4(i,x);
	}
	cur^=b(s[x]);
}

void dfs5(int x,int fa){
	cur^=b(s[x]);
	
	//printf("a%d %d %d\n",x,fa,cur^b(s[rt]));
	
	h[x]+=g[cur^b(s[rt])];
	for(int i=1;i<=20;i++){
		h[x]+=g[cur^b(s[rt])^b(i)];
	}
	if(__builtin_popcount(cur^b(s[rt]))<=1){h[rt]++;}
	
	for(auto i:v[x]){
		if(i==fa||del[i])continue;
		dfs5(i,x);
		h[x]+=h[i];
	}
	f[x]+=h[x];
	cur^=b(s[x]);
}

void dfs6(int x,int fa){
	cur^=b(s[x]);
	g[cur]=0;
	h[x]=0;
	for(auto i:v[x]){
		if(i==fa||del[i])continue;
		dfs6(i,x);
	}
	cur^=b(s[x]);
}

void work(int x){
	//printf("rt %d\n",x);
	cur=0;
	g[0]++;
	for(auto i:v[x]){
		if(del[i])continue;
		dfs3(i,x);
	}
	
	for(auto i:v[x]){
		if(del[i])continue;
		dfs4(i,x);
		dfs5(i,x);
		dfs3(i,x);
		h[x]+=h[i];
	}
	f[x]+=h[x]/2+1;
	
	h[x]=0;g[0]--;
	for(auto i:v[x]){
		if(del[i])continue;
		dfs6(i,x);
	}
}

void dfz(int x){
	rt=0;num=0;
	dfs(x,0);
	dfs2(x,0);
	work(rt);
	del[rt]=1;
	for(auto i:v[rt]){
		if(!del[i]){
			dfz(i);
		}
	}
}

int main(){
	cin.tie(0);
	cin>>n;
	for(i=1;i<n;i++){
		cin>>j>>k;
		v[j].push_back(k);
		v[k].push_back(j);
	}
	cin>>s+1;
	for(i=1;i<=n;i++)s[i]-='a'-1;
	
	dfz(1);
	
	for(i=1;i<=n;i++)cout<<f[i]<<' ';
}
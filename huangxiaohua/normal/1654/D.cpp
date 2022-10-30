#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353

int i,j,k,t,n,m,p[200500],mx[200500],cur[200500];
vector<tuple<int,int,int> > v[200500];
ll sb,inv[200500],res;
ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}

void init(){
	for(i=2;i<=200000;i++){
		inv[i]=ksm(i,M-2);
		if(!p[i]){
			for(j=i;j<=200000;j+=i){
				if(!p[j])p[j]=i;
			}
		}
	}
}

void add(int x){
	while(x>1){cur[p[x]]--;x/=p[x];}
}

void del(int x){
	while(x>1){mx[p[x]]=max(mx[p[x]],++cur[p[x]]);x/=p[x];}
}

void dfs(int x,int fa){
	for(auto [i,a,b]:v[x]){
		if(i==fa)continue;
		add(a);del(b);
		dfs(i,x);
		add(b);del(a);
	}
}

void add2(int x){
	while(x>1){sb=sb*p[x]%M;x/=p[x];}
}

void del2(int x){
	while(x>1){sb=sb*inv[p[x]]%M;x/=p[x];}
}

void dfs2(int x,int fa){
	res+=sb;
	for(auto [i,a,b]:v[x]){
		if(i==fa)continue;
		add2(a);del2(b);
		dfs2(i,x);
		add2(b);del2(a);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	init();
	cin>>t;
	while(t--){
		cin>>n;
		memset(mx,0,n*4+50);
		memset(cur,0,n*4+50);
		for(i=1;i<=n;i++)v[i].clear();
		for(i=1;i<n;i++){
			int x,y,a,b;
			cin>>x>>y>>a>>b;
			v[x].push_back({y,b,a});
			v[y].push_back({x,a,b});
		}
		dfs(1,0);
		res=0;
		sb=1;
		for(i=1;i<=n;i++){
			for(j=1;j<=mx[i];j++)sb=sb*i%M;
		}
		dfs2(1,0);
		cout<<res%M<<'\n';
	}
}
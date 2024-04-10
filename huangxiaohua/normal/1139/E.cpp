#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,x,y,z,st,ed,dep[10005],q[10005],it,a[10005],b[10005];
int res,w[50050],sb,cur,ans[5050];
vector<pair<int,int> >v[10005];
pair<int,int> c[10050];

void add(int x,int y){
	it++;w[it+it]=1;
	v[x].push_back({y,it+it});
	v[y].push_back({x,it+it+1});
}

int dfs(int x,int wt){
	if(x==ed)return wt;
	ll sb=0,sb2=0;
	for(auto [i,j]:v[x]){
		if(!w[j]||dep[i]!=dep[x]+1)continue;
		sb=dfs(i,min(wt,w[j]));
		w[j]-=sb;
		w[j^1]+=sb;
		wt-=sb;
		sb2+=sb;
	}
	if(!sb2)return dep[x]=0;
	return sb2;
}

int bfs(){
	memset(dep,0,sizeof(dep));
	int l=1,r=1,x;q[l]=st;dep[st]=1;
	while(l<=r){
		x=q[l++];
		for(auto [i,j]:v[x]){
			if(!w[j]||dep[i])continue;
			q[++r]=i;dep[i]=dep[x]+1;
		}
	}
	return dep[ed];
}

int main(){
	scanf("%d%d",&n,&m);
	st=1;ed=m+5003;
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	for(i=1;i<=n;i++)scanf("%d",&b[i]);
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%d",&k);
		c[i]={b[k]+1,a[k]+m+2};
		a[k]=b[k]=-1;
	}
	for(i=1;i<=m;i++)add(1,i+1);
	add(m+2,ed);
	for(i=1;i<=n;i++){
		if(-1==a[i])continue;
		add(b[i]+1,a[i]+m+2);
	}
	for(i=t;i>=1;i--){
		while(1&&cur<=5000){
			while(bfs())res+=dfs(st,10000);
			if(res<cur+1)break;
			cur++;add(cur+m+2,ed);
		}
		auto [x,y]=c[i];
		add(x,y);
		ans[i]=cur;
	}
	for(i=1;i<=t;i++)printf("%d\n",ans[i]);
}
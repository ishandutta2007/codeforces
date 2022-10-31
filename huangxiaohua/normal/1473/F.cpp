#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,x,y,z,st,ed,dep[6005],q[6005],it,lst[105],a[3050],b[3050];
ll res,sb,w[600500];
vector<pair<int,int> >v[6005];

ll dfs(int x,ll wt){
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
	memset(dep,0,n*4+50);
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

void add(int x,int y,int z){
	it++;w[it*2]=z;
	v[x].push_back({y,it+it});
	v[y].push_back({x,it+it+1});
}

int main(){
	scanf("%d",&n);
	st=n+1;ed=n+2;
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	for(i=1;i<=n;i++)scanf("%d",&b[i]);
	for(i=1;i<=n;i++){
		if(b[i]>0){
			add(st,i,b[i]);
			res+=b[i];
		}
		else{
			add(i,ed,-b[i]);
		}
		for(j=1;j<=100;j++){
			if(!(a[i]%j)&&lst[j]){
				add(i,lst[j],1e9);
			}
		}
		lst[a[i]]=i;
	}
	while(bfs()){
		res-=dfs(st,1e18);
	}
	printf("%lld",res);
}
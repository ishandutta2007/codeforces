#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,l[200500],r[200500],it,f[200500],del[200500],lst,id[200500];
int g[200500];
ll res=-1e18,r1,r2;
vector<int> v[200500];
priority_queue<pair<int,int> >q;

void add(int x,int y){for(;x<=n;x+=(-x&x)){g[x]+=y;}}
int get(int x,int y=0){for(;x;x-=(-x&x)){y+=g[x];}return y;}

void dfs(int x,int fa,int dep){
	f[x]=fa;
	l[x]=9999999;
	if(fa&&v[x].size()==1){
		l[x]=r[x]=++it;
		id[it]=x;
		add(it,dep-lst);
		lst=dep;
		q.push({dep,it});
		return;
	}
	for(auto i:v[x]){
		if(i==fa)continue;
		dfs(i,x,dep+1);
		l[x]=min(l[x],l[i]);
		r[x]=max(r[x],r[i]);
	}
}

int main(){
	ios::sync_with_stdio(0);
	del[0]=1;
	cin>>n>>m;
	r2=-n;
	for(i=1;i<n;i++){
		cin>>j>>k;
		v[j].push_back(k);
		v[k].push_back(j);
	}
	dfs(1,0,1);
	if(it<=m){
		res=min(max(it,n/2),m);
		res=res*(n-res);
		cout<<res;return 0;
	}
	while(m--){
		auto [x,y]=q.top();q.pop();	
		if(x!=get(y)){
			m++;
			q.push({get(y),y});
			continue;
		}
		r1+=x;r1--;
		r2++;r2+=x;
		k=id[y];
		while(!del[k]){
			add(l[k],-1);
			add(r[k]+1,1);
			del[k]=1;
			k=f[k];
		}
	}
	while((r1+r2)<-1&&r2<0){
		r2++;r1++;
	}
	cout<<r1*r2;
}
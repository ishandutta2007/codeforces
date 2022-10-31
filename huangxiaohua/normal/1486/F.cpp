#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,x,y;
int fa[300500][21],l[300500],r[300500],it,dep[300500],f[300500],p[300500];
ll res;
vector<int> v[300500];

void add(int x,int y){
	for(;x<=n;x+=(-x&x))f[x]+=y;
}
int get(int x,int y=0){
	for(;x;x-=(-x&x)){y+=f[x];}return y;
}

struct sb{
	int x,y,ls,rs;
}s;

vector<struct sb> lca[300500];

void dfs(int x,int f){
	dep[x]=dep[f]+1;
	l[x]=++it;
	fa[x][0]=f;
	for(int i=1;i<=19;i++){
		fa[x][i]=fa[fa[x][i-1]][i-1];
	}
	for(auto i:v[x]){
		if(i==f)continue;
		dfs(i,x);
	}
	r[x]=it;
}

void get1(int id,int x,int y){
	if(x==y){
		lca[x].push_back(s);return;
	}
	if(dep[x]>dep[y])swap(x,y);
	for(int i=19;i>=0;i--){
		if(dep[fa[y][i]]>dep[x])y=fa[y][i];
	}
	if(fa[y][0]==x){
		s.ls=y;
		lca[x].push_back(s);return;
	}
	if(dep[y]!=dep[x])y=fa[y][0];
	for(int i=19;i>=0;i--){
		if(fa[y][i]!=fa[x][i]){
			y=fa[y][i];x=fa[x][i];
		}
	}
	s.ls=x;s.rs=y;
	lca[fa[x][0]].push_back(s);
}

bool cmp(int x,int y){return dep[x]<dep[y];}

map<int,int> mp1;
map<pair<int,int>,int >mp2;

int main(){
	cin.tie(0);
	cin>>n;p[n]=n;
	for(i=1;i<n;i++){
		cin>>j>>k;
		v[j].push_back(k);
		v[k].push_back(j);
		p[i]=i;
	}
	dfs(1,0);
	cin>>m;
	for(i=1;i<=m;i++){
		cin>>x>>y;
		s.x=x;s.y=y;
		s.ls=s.rs=0;
		get1(i,x,y);
	}
	sort(p+1,p+n+1,cmp);
	for(i=1;i<=n;i++){
		k=0;mp1.clear();mp2.clear();
		for(auto [x,y,ls,rs]:lca[p[i]]){
			res+=k++;
			if(ls>rs)swap(ls,rs);
			if(ls){
				res-=mp1[ls];mp1[ls]++;
				res-=get(r[ls])-get(l[ls]-1);
			}
			if(rs){
				res-=mp1[rs];mp1[rs]++;
				res-=get(r[rs])-get(l[rs]-1);
			}
			if(ls&&rs){
				res+=mp2[{ls,rs}];mp2[{ls,rs}]++;
			}
			res+=get(r[p[i]])-get(l[p[i]]-1);
		}
		for(auto [x,y,ls,rs]:lca[p[i]]){
			add(l[x],1);add(l[y],1);
		}
	}
	cout<<res;
}
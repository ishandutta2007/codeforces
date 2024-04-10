#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#pragma GCC optimize("Ofast")

int i,j,k,n,t,m,x,y,mp[200500],a[200500],sb[200500],w,w2;
int fa[200500],fa2[200500];

struct bian{
	int x,y,w;
	bool operator<(const bian a)const{return w<a.w;}
}b,tmp;

vector<bian> s;

int find(int x){
	if(x==fa[x]){return x;}
	return fa[x]=find(fa[x]);
}

int find2(int x){
	if(x==fa2[x]){return x;}
	return fa2[x]=find2(fa2[x]);
}

ll get1(int x,int y){
	ll ans=0;
	for(i=1;i<=n;i++){
		fa[i]=i;
	}
	for(auto i:s){
		if(i.x==x&&i.y==y&&!i.w){continue;}
		if(i.x==y&&i.y==x&&!i.w){continue;}
		if(find(i.x)==find(i.y)){continue;}
		fa[find(i.x)]=fa[find(i.y)];ans+=i.w;
	}
	return ans;
}



void solve1(){
	static int c[750][750]={0};
	ll res=1e18;
	int i,j;
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&w);
		c[x][y]=c[y][x]=w;
		sb[x]++;sb[y]++;
		w2^=w;
	}
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			b.x=i;b.y=j;b.w=c[i][j];
			s.push_back(b);
			if(c[i][j]){continue;}
			b.w=w2;
			s.push_back(b);
		}
	}
	sort(s.begin(),s.end());
	k=1;
	if(((n*n-n)/2-m)>=n+5||!w2){
		res=get1(0,0);
	}
	else{
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				if(c[i][j]){continue;}
				res=min(get1(i,j),res);
			}
		}
	}
	printf("%lld",res);
}

ll get2(){
	ll ans=0;
	for(i=1;i<=n;i++){
		fa[i]=i;
	}
	for(auto i:s){
		if(find(fa2[i.x])==find(fa2[i.y])){continue;}
		fa[find(fa2[i.x])]=fa[find(fa2[i.y])];ans+=i.w;
	}
	return ans;
}

void solve2(){
	unordered_map<int,unordered_map<int,int> > mp;
	int i,j;
	for(i=1;i<=n;i++){
		fa2[i]=i;
	}
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&w);
		b.x=x;b.y=y;b.w=w;
		s.push_back(b);
		mp[x][y]=mp[y][x]=1;
	}
	sort(s.begin(),s.end());
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j){continue;}
			find2(i);find2(j);
			if(!mp[i][j]){fa2[fa2[j]]=fa2[i];break;}
		}
	}
	for(i=1;i<=n;i++){
		find2(i);
	}
	printf("%lld",get2());
}

int main(){
	scanf("%d%d",&n,&m);
	if(n<=666){solve1();}
	else{solve2();}
}
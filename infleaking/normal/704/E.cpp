#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
struct pi{ll x,y;};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
pi make(ll a,ll b=1){return (pi){a,b};}
pi div(pi a){ll d=gcd(a.x,a.y);d*=a.y<0?-1:1;return make(a.x/d,a.y/d);}
pi div1(ll a,ll b){return div(make(a,b));}
pi operator+(pi a,pi b){ll z=a.y/gcd(a.y,b.y)*b.y;return div1(a.x*(z/a.y)+b.x*(z/b.y),z);}
pi operator-(pi a,pi b){b.x*=-1;return a+b;}
pi operator*(pi a,pi b){return div1(a.x*b.x,a.y*b.y);}
pi operator/(pi a,pi b){return div1(a.x*b.y,a.y*b.x);}
bool operator<(pi a,pi b){if ((a.y<0)!=(b.y<0))swap(a,b);return a.x*b.y<a.y*b.x;}
bool operator==(pi a,pi b){return a.x*b.y==a.y*b.x;}
pi now;
struct node{pi s;ll v;};
bool operator<(node a,node b){
	pi a1=a.s+make(a.v)*now,b1=b.s+make(b.v)*now;
	if (a1==b1){
		if (a.v==b.v)return a.s<b.s;
		return a.v<b.v;
	}
	return a1<b1;
}
pi crash(node a,node b){
	if (a.v==b.v)return make(1e9);
	pi res=(b.s-a.s)/make(a.v-b.v);
	if (res<now)return make(1e9);
	else return res;
}
multiset<node> s;
typedef multiset<node>::iterator it;
multiset<pi> lim;
int dfn[N],ld[N],size[N],hs[N],n,m;
int w[N],ne[N],la[N],t,fa[N],dep[N];
void link(int x,int y){
	w[++t]=y;
	ne[t]=la[x];
	la[x]=t;
}
struct que{node s;int ty;pi t;};
vector<que> vec[N];
bool comp(que a,que b){
	if (a.t==b.t)return a.ty<b.ty;
	return a.t<b.t;
}
#define del(a,b) a.erase(a.find(b))
void dfs1(int x){
	for (int y=la[x];y;y=ne[y]){
		int z=w[y];
		if (z==fa[x])continue;
		fa[z]=x;
		dep[z]=dep[x]+1;
		dfs1(z);
		size[x]+=size[z];
		if (size[z]>size[hs[x]])hs[x]=z;
	}size[x]++;
}
void dfs2(int x){
	ld[x]=hs[fa[x]]==x?ld[fa[x]]:x;
	for (int y=la[x];y;y=ne[y])
		if (w[y]!=fa[x])dfs2(w[y]);
}
int lca(int x,int y){
	while (ld[x]!=ld[y]){
		if (dep[ld[x]]<dep[ld[y]])swap(x,y);
		x=fa[ld[x]];
	}return dep[x]<dep[y]?x:y;
}
void init(){
	now=(pi){0,1}; 
	node a=(node){make(-1e9),-1},b=(node){make(1e9),1};
	s.clear();
	s.insert(a);
	s.insert(b);
	lim.clear();
	lim.insert(crash(a,b));
}
int main(){
	cin>>n>>m;
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		link(x,y);
		link(y,x);
	}
	dfs1(1);dfs2(1);
	while (m--){
		int t,c,x,y,z,d;
		scanf("%d%d%d%d",&t,&c,&x,&y);
		z=lca(x,y);d=dep[x]+dep[y]-2*dep[z];
		node s1=(node){make(t*c+dep[x]),-c},s2=(node){make(2*dep[z]-dep[x]-t*c),c};
		pi now1=make(t),now2=make(t)+make(d,c);
		while (ld[x]!=ld[y]){
			if (dep[ld[x]]>dep[ld[y]]){
				int x0=fa[ld[x]];
				vec[ld[x]].push_back((que){s1,1,now1});
				now1=now1+make(dep[x]-dep[x0],c);
				vec[ld[x]].push_back((que){s1,2,now1});
				x=x0;
			}
			else {
				int y0=fa[ld[y]];
				vec[ld[y]].push_back((que){s2,2,now2});
				now2=now2-make(dep[y]-dep[y0],c);
				vec[ld[y]].push_back((que){s2,1,now2});
				y=y0;
			}
		}
		if (dep[x]<dep[y]){
			vec[ld[x]].push_back((que){s2,1,now1});
			vec[ld[x]].push_back((que){s2,2,now2});
		}
		else {
			vec[ld[x]].push_back((que){s1,1,now1});
			vec[ld[x]].push_back((que){s1,2,now2});
		}
	}
	pi ans=make(1e9);
	for (int x=1;x<=n;x++){
		if (ld[x]!=x)continue;
		init();
		sort(vec[x].begin(),vec[x].end(),comp);
		for (auto i:vec[x]){
			now=i.t;
			if (!(now<*lim.begin())){
				if (*lim.begin()<ans)ans=*lim.begin();
				break;
			}
			if (i.ty==1){
				it x0=s.find(i.s);
				if (x0!=s.end()){
					if (now<ans)ans=now;
					break;
				}
				s.insert(i.s);
				it x=s.find(i.s),L=--s.find(i.s),R=++s.find(i.s);
				del(lim,crash(*L,*R));
				lim.insert(crash(*L,i.s));
				lim.insert(crash(*R,i.s));
			}
			else {
				it x=s.find(i.s),L=--s.find(i.s),R=++s.find(i.s);
				assert(x!=s.end());
				del(lim,crash(*L,i.s));
				del(lim,crash(*R,i.s));
				lim.insert(crash(*L,*R));
				del(s,i.s);
			}
		}
	}
	if (ans==make(1e9))cout<<-1<<endl;
	else {
		ans=div(ans);
		printf("%.12lf\n",(double)ans.x/ans.y);
	}
}
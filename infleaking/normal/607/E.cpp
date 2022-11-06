#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#include<bits/stdc++.h>
using namespace std;
typedef double ld;
const int N=2e5+10;
const ld eps=1e-9;
struct dot{ld x,y;}O,st;
struct line{dot u,v;}p[N];
dot operator +(dot a,dot b){return (dot){a.x+b.x,a.y+b.y};}
dot operator -(dot a,dot b){return (dot){a.x-b.x,a.y-b.y};}
dot operator *(dot a,dot b){return (dot){a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x};}
dot operator *(dot a,ld b){return (dot){a.x*b,a.y*b};}
ld cross(dot a,dot b){return (a.x*b.y-a.y*b.x);}
dot cross(line a,line b){return a.u+a.v*(cross(b.u-a.u,b.v)/cross(a.v,b.v));}
ld dis(dot a){return sqrt(a.x*a.x+a.y*a.y);}
ld dis(dot a,line b){return cross(a-b.u,b.v)/dis(b.v);}//  
int n,m;
int tr[N],M;
#define low(x) (x&(-x))
void add(int x,int v){
	for (;x<=M;x+=low(x))tr[x]+=v;
}
int query(int x){
	int ans=0;
	for (;x;x-=low(x))ans+=tr[x];
	return ans;
}
typedef pair<dot,int> pi;
vector<pi> d;
ld at[N];
int r[N],cnt[N],la[N];
bool comp(int a,int b){
	return at[a]<at[b];
}
int check(ld lim){
	d.clear();
	unsigned ans=0;
	for (int i=1;i<=n;i++){
		ld D=dis(O,p[i]);
		if (abs(dis(O,p[i]))>lim)continue;
		dot M=(dot){0,-1}*p[i].v;
		ld ang=acos(D/lim);
		d.push_back( make_pair((dot){cos(ang),sin(ang)}*M,i) );
		d.push_back( make_pair((dot){cos(ang),-sin(ang)}*M,i) );
		ans+=d.size()/2-1;
	}ans*=2;
	for (int i=0;i<d.size();i++)r[i]=i,at[i]=atan2(d[i].first.y,d[i].first.x);
	sort(r,r+d.size(),comp);
	for (int i=0;i<d.size();i++)r[i+d.size()]=r[i];
	M=2*d.size();
	for (int i=0;i<M;i++){
		int x=d[r[i]].second;
		++cnt[x];
		if (cnt[x]==2||cnt[x]==3)ans-=query(la[x]+1);
		if (cnt[x]>1){
			add(1,1);
			add(la[x]+1,-1);
		}
		la[x]=i;
	}
	for (int i=1;i<=M;i++)tr[i]=0;
	for (int i=1;i<=n;i++)cnt[i]=la[i]=0;
	return ans/2;
}
ld getint(){
	int x;
	scanf("%d",&x);
	return x*0.001;
}
map<int,int> T[N*4];
int pl,pr,px,pv;
void ins(int x,int l,int r){
	if (pr<l||r<pl)return;
	if (pl<=l&&r<=pr){
		if (!(T[x][px]+=pv))
			T[x].erase(px);
//		assert(T[x][px]==0||T[x][px]==pv);
		return;
	}
	ins(x+x,l,l+r>>1);
	ins(x+x+1,l+r+2>>1,r);
}
ld Ans;
int cnt1;
void go(int x,int l,int r){
	for (auto i:T[x]){
		if (i.first<pv){
			Ans+=dis(cross(p[pv],p[i.first])),cnt1++;
		}
	}
	if (l==r)return;
	if (px<=(l+r>>1))go(x+x,l,l+r>>1);
	else go(x+x+1,l+r+2>>1,r);
}
int main(){
	cin>>n;
	st=(dot){getint(),getint()};
	cin>>m;
	for (int i=1;i<=n;i++){
		ld a=getint(),b=getint();
		dot z0=(dot){0,b},z1=(dot){1,a+b};
		p[i]=(line){z0-st,z1-z0};
	}
	ld LIM=0;
	for (ld u=1e12;u>eps;u/=2){
		int k=check(LIM+u);
		if (k<m)LIM+=u;
	}
	int res=check(LIM);
	for (int i=0;i<d.size();i++){
		int x=d[r[i]].second;
		++cnt[x];
		if (cnt[x]>1){
			pl=la[x],pr=i,px=x,pv=1;
			ins(1,0,M);
		}
		la[x]=i;
	}
	for (int i=d.size();i<M;i++){
		int x=d[r[i]].second;
		++cnt[x];
		pl=i-d.size(),pr=la[x],px=x,pv=-1;
		ins(1,0,M);
		if (cnt[x]==3){
			px=la[x];
			pv=x;
			go(1,0,M);
			pl=la[x],pr=i,px=x,pv=1;
			ins(1,0,M);
		}
		la[x]=i;
	}
//	assert(cnt2==res);
//	if (m==30)cout<<cnt1<<' '<<cnt2<<' '<<res<<endl;
	assert(cnt1<=res);
	assert(cnt1>=res);
	printf("%.12lf\n",Ans-LIM*(cnt1-m));
}
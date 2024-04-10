#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
inline int read(){
	char c,p=0;int w;
	while(!isdigit(c=getchar()))if(c=='-')p=1;w=c^'0';
	while(isdigit(c=getchar()))w=w*10+(c^'0');
	return p?-w:w;
}
const int N=2e5+5;
vector< pair<int,int> >g[N];
int n,m,a[N];
#define ls o<<1
#define rs o<<1|1
long long add[N<<2],mxx[N<<2],f[N];
inline void pushdown(int o){
	if(add[o]){
		add[ls]+=add[o],add[rs]+=add[o];
		mxx[ls]+=add[o],mxx[rs]+=add[o];
		add[o]=0;
	}
}
inline void update(int o,int l,int r,int x,int y,long long k){
	if(x<=l&&r<=y){add[o]+=k,mxx[o]+=k;return;}
	if(y<l||x>r)return;
	pushdown(o);
	int mid=l+r>>1;
	update(ls,l,mid,x,y,k);update(rs,mid+1,r,x,y,k);
	mxx[o]=max(mxx[ls],mxx[rs]);
}
inline long long query(int o,int l,int r,int x,int y){
	if(x<=l&&r<=y)return mxx[o];
	if(y<l||x>r)return -1e17;
	pushdown(o);
	int mid=l+r>>1;
	return max(query(ls,l,mid,x,y),query(rs,mid+1,r,x,y));
}
int main(){
	n=read();m=read();
	REP(i,1,n)a[i]=read();
	while(m--){int x=read(),y=read();g[y].push_back({x,read()});}
	#define all 1,1,n
	REP(i,1,n){
		update(all,1,i,-a[i]);
		for(auto t:g[i])update(all,1,t.first,t.second);
		update(all,i+1,i+1,f[i]=max(f[i-1],query(all,1,i)));
	}
	cout<<f[n];
	return 0;
}
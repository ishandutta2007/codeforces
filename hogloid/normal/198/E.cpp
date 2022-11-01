#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef unsigned long long int lint;
typedef pair<int,int> pi;
struct gr{
	lint dst;
	lint p,r;
	lint m;
	int id,pos;
	gr(){}
	gr(lint a){
		dst=a;
		id=INF;
	}
	bool operator <(const gr& val)const {
		if(dst!=val.dst) return dst<val.dst;
		return id<val.id;
	}
};
int p,r,n;
gr own[250005],grip[250005];
bool cmp(int i,int j){
	return own[i].m<=own[j].m;
}
struct segtree{
	int val[1000005];
	int n;
	int n_;
	void init(int n__){
		n_=n__;
		n=1;
		while(n<n_) n<<=1;
		REP(i,n*2) val[i]=n_;
		REP(i,n_) val[i+n-1]=grip[i].id;
		for(int i=n-2;i>=0;--i){
			if(cmp(val[i*2+1],val[i*2+2])) val[i]=val[i*2+1];
			else val[i]=val[i*2+2];
		}
	}
	int query(int a,int b,int i,int l,int r){
		if(a<=l && r<=b) return val[i];
		if(b<=l || r<=a) return n_;
		int md=(l+r)>>1;
		int lef=query(a,b,i*2+1,l,md),ri=query(a,b,i*2+2,md,r);
		if(cmp(lef,ri)) return lef;
		return ri;
	}
	void del(int pos){
		pos+=n-1;
		val[pos]=n_;
		while(pos){
			pos=(pos-1)/2;
			if(cmp(val[pos*2+1],val[pos*2+2])) val[pos]=val[pos*2+1];
			else val[pos]=val[pos*2+2];
		}
	}
};

segtree seg;
pair<lint,lint> got[250005];
int main(){
	int sx,sy;
	scanf("%d%d%d%d%d",&sx,&sy,&p,&r,&n);
	REP(i,n){
		int x,y,m,p,r;
		scanf("%d%d%d%d%d",&x,&y,&m,&p,&r);
		own[i].dst=(x-sx)*(lint)(x-sx)+(y-sy)*(lint)(y-sy);
		own[i].p=p;
		own[i].m=m;
		own[i].r=r*(lint)r;
		own[i].id=i;
		grip[i]=own[i];
	}
	own[n].m=1e18;
	sort(grip,grip+n);
	REP(i,n) own[grip[i].id].pos=i;
	
	seg.init(n);
	int m=0;
	got[m++]=mp(p,r*(lint)r);
	int res=0;
	while(m>0){
		pair<lint,lint> cur=got[m-1];--m;
		int lim=upper_bound(grip,grip+n,gr(cur.sc))-grip;
		int who;
		while(1){
			who=seg.query(0,lim,0,0,seg.n);
			if(own[who].m>cur.fr) break;
			got[m++]=mp(own[who].p,own[who].r);
			seg.del(own[who].pos);
			++res;
		}
	}
	printf("%d\n",res);

	
	return 0;
}
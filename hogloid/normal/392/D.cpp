#include<bits/stdc++.h>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#ifndef ONLINE_JUDGE
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;

namespace std{
	template<class S,class T>
	ostream &operator <<(ostream& out,const pair<S,T>& a){
		out<<'('<<a.fr<<','<<a.sc<<')';
		return out;
	}
}
lint readL(){
	lint res;
#ifdef ONLINE_JUDGE
	scanf("%I64d",&res);
#else
	scanf("%lld",&res);
#endif
	return res;
}
void printL(lint res){
#ifdef ONLINE_JUDGE
	printf("%I64d",res);
#else
	printf("%lld",res);
#endif
}
const int INF=5e8;


struct segtree{
	int val[400005],mini[400005],maxi[400005],all[400005];
	int n;
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
		memset(all,-1,sizeof(all));
		REP(i,n*2) val[i]=INF;

		REP(i,n*2) mini[i]=0;
		REP(i,n*2) maxi[i]=0;
		
		REP(i,n_) val[i+n-1]=i;
		for(int i=n-2;i>=0;--i) val[i]=min(val[i*2+1],val[i*2+2]);
	}
	void push(int i,int l,int r){
		if(all[i]==-1) return;
		int md=(l+r)>>1;
		mini[i*2+1]=maxi[i*2+1]=all[i*2+1]=all[i];
		val[i*2+1]=l+all[i];

		maxi[i*2+2]=mini[i*2+2]=all[i*2+2]=all[i];
		val[i*2+2]=md+all[i];

		all[i]=-1;
	}

	void set(int a,int b,int i,int l,int r,int v){
		if(mini[i]>=v) return;
		if(a<=l && r<=b && maxi[i]<=v){
			all[i]=maxi[i]=mini[i]=v;
			val[i]=v+l;
			return;
		}
		if(b<=l || r<=a) return;

		push(i,l,r);
		int md=(l+r)>>1;
		set(a,b,i*2+1,l,md,v);
		set(a,b,i*2+2,md,r,v);
		val[i]=min(val[i*2+1],val[i*2+2]);
		maxi[i]=max(maxi[i*2+1],maxi[i*2+2]);
		mini[i]=min(mini[i*2+1],mini[i*2+2]);
		all[i]=-1;
	}
	int query(int a,int b,int i,int l,int r){
		if(a<=l && r<=b) return val[i];
		if(b<=l || r<=a) return INF;
		int md=(l+r)>>1;
		push(i,l,r);
		return min(query(a,b,i*2+1,l,md),query(a,b,i*2+2,md,r));
	}
};
segtree seg;

map<int,int> app[3];
int ar[3][100005];
int n;
int main(){
	cin>>n;
	seg.init(n+1);
	REP(t,3) REP(i,n){
		int a;scanf("%d",&a);
		ar[t][i]=a;
		if(!app[t].count(a)) app[t][a]=i;
	}
	REPN(t,3,1) REP(i,n){
		if(!app[0].count(ar[t][i])){
			bool ex1=app[1].count(ar[t][i]),ex2=app[2].count(ar[t][i]);
			int pos1=n,pos2=INF;
			if(ex1) pos1=app[1][ar[t][i]];
			if(ex2) pos2=app[2][ar[t][i]];

			seg.set(0,pos1+1,0,0,seg.n,pos2+1);
			dump(ar[t][i]);dump(pos1+1);dump(pos2+1);
		}
	}
	
	
	int res=INF;
	for(int i=n-1;i>=-1;--i){
		chmin(res,i+1+seg.query(0,n+1,0,0,seg.n));
		dump(i+1);dump(seg.query(0,n+1,0,0,seg.n));
		if(i<0) break;

		if(app[0][ar[0][i]]==i){
			int v=ar[0][i];
			bool ex1=app[1].count(ar[0][i]),ex2=app[2].count(ar[0][i]);
			int pos1=n,pos2=INF;
			if(ex1) pos1=app[1][v];
			if(ex2) pos2=app[2][v];

			if(!ex1 && !ex2) break;
			dump(pos1);dump(pos2);
			seg.set(0,pos1+1,0,0,seg.n,pos2+1);
		}
	}

	cout<<res<<endl;

	return 0;
}
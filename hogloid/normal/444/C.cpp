#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<set>
#include<vector>
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

struct segtree{
	lint val[400005],lazy[400005];
	int n;
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n*2) val[i]=0;
	}
	void push(int i,int len){
		if(lazy[i]){
			val[i*2+1]+=lazy[i]*len/2;
			val[i*2+2]+=lazy[i]*len/2;

			lazy[i*2+1]+=lazy[i];
			lazy[i*2+2]+=lazy[i];
			lazy[i]=0;
		}
	}

	void add(int a,int b,int i,int l,int r,int v){
		if(a<=l && r<=b) {
			lazy[i]+=v;
			val[i]+=v*(lint)(r-l);
			return;
		}
		if(b<=l || r<=a) return ;
		int md=(l+r)>>1;
		push(i,r-l);
		add(a,b,i*2+1,l,md,v);
		add(a,b,i*2+2,md,r,v);
		val[i]=val[i*2+1]+val[i*2+2];
	}
	lint query(int a,int b,int i,int l,int r){
		if(a<=l && r<=b) return val[i];
		if(b<=l || r<=a) return 0;
		int md=(l+r)>>1;
		push(i,r-l);
		return query(a,b,i*2+1,l,md)+query(a,b,i*2+2,md,r);
	}
};

int n,m;
set<pair<pi,int> > rle;

segtree seg;

pair<pi,int> ins[10];
int main(){
	cin>>n>>m;
	seg.init(n);
	REP(i,n) rle.insert(mp(mp(i,i+1),i+1));
	REP(i,m){
		int t,l,r;scanf("%d%d%d",&t,&l,&r);
		--l;
		if(t==1){
			int x;scanf("%d",&x);

			auto it=rle.lower_bound(mp(mp(l+1,-1),-1));
			--it;
			
			int cnt=0;
			dump(i);
			while(it!=rle.end() && it->fr.fr<r){
				prl;
				
				if(it->fr.fr<l) ins[cnt++]=mp(mp(it->fr.fr,l),it->sc);
				if(r<it->fr.sc) ins[cnt++]=mp(mp(r,it->fr.sc),it->sc);
				
				dump(it->fr);dump(l);dump(r);
				int L=max(it->fr.fr,l),R=min(it->fr.sc,r);
				int dif=abs(it->sc-x);
				dump(dif);
				seg.add(L,R,0,0,seg.n,dif);
				rle.erase(it++);
			}
			ins[cnt++]=mp(mp(l,r),x);

			REP(j,cnt) rle.insert(ins[j]);
		}else{
			lint res=seg.query(l,r,0,0,seg.n);
			cout<<res<<'\n';
		}
	}



	return 0;
}
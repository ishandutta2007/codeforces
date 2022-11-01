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

const int INF1=1e9+5;
const lint INF2=1e18;
int n,m;
lint st[100005],mx[100005],incr[100005];
typedef pair<pair<lint,lint>,lint> key;
struct segtree{
	int start[400005];
	vector<key> val[270000];//((div-time,mx-sum),incr-sum)
	int n;
	key make(int m,int incr){
		key res;
		if(incr==0) res.fr.fr=INF1;
		else res.fr.fr=m/incr;
		//...res.fr.fr] time*incr
		//otherwise  mx

		res.fr.sc=m;
		res.sc=incr;
		return res;
	}

	void mrg(int i){
		if(start[i*2+1]==start[i*2+2]) start[i]=start[i*2+1];
		else if(start[i*2+2]==-2) start[i]=start[i*2+1];
		else start[i]=-1;
	}
	void push(int i){
		if(start[i]>=0){
			start[i*2+1]=start[i];
			start[i*2+2]=start[i];
		}
	}

	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n) start[i+n-1]=-2;
		REP(i,n_){
			start[i+n-1]=0;
			val[i+n-1].pb(make(mx[i],incr[i]));
		}
		for(int i=n-2;i>=0;--i){
			mrg(i);
			val[i].resize(val[i*2+1].size()+val[i*2+2].size());
			merge(ALL(val[i*2+1]),ALL(val[i*2+2]),val[i].begin());
		}

		for(int i=n-2;i>=0;--i) if(!val[i].empty()){
			REP(j,val[i].size()-1){
				val[i][j+1].fr.sc+=val[i][j].fr.sc;
				val[i][j+1].sc+=val[i][j].sc;
			}
		}
	}
	lint query(int a,int b,int i,int l,int r,int t){
		if(a<=l && r<=b && (start[i]>0 || r-l==1)){
			int dif=t-start[i];
			if(start[i]==0){
				start[i]=t;
				return min(mx[l],st[l]+incr[l]*t);
			}
			int lb=lower_bound(ALL(val[i]),(key)mp(mp(dif,-1),-1))-val[i].begin();
			lint res=0;
			if(lb>0){
				--lb;
				res+=val[i][lb].fr.sc;
				res+=(val[i].back().sc-val[i][lb].sc)*dif;
			}else{
				res+=val[i].back().sc*dif;
			}
			start[i]=t;
			return res;
		}
		if(b<=l || r<=a) return 0;
		int md=(l+r)>>1;
		push(i);
		lint lch=query(a,b,i*2+1,l,md,t),rch=query(a,b,i*2+2,md,r,t);
		mrg(i);
		return lch+rch;
	}
};
segtree seg;

int main(){
	cin>>n;
	REP(i,n){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		st[i]=a;mx[i]=b;incr[i]=c;
	}
	seg.init(n);
	cin>>m;
	REP(hoge,m){
		int t,l,r;scanf("%d%d%d",&t,&l,&r);--l;
		lint res=seg.query(l,r,0,0,seg.n,t);
		cout<<res<<'\n';
	}




	return 0;
}
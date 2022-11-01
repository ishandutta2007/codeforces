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
typedef pair<lint,lint> pi;

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
const lint INF2=1e18;

int n;
int ar[100005];
pi ar2[100005];//(grad,init)


bool cmp(const pi& a,const pi& b){
	if(a.sc!=b.sc) return a.sc<b.sc;
	return a.fr<b.fr;
}

struct segtree{
	vector<pi> val[400005];
	int n;
	
	double cross(const pi& a,const pi& b){
		return (a.sc-b.sc)/(double)(b.fr-a.fr);
	}

	void fix(vector<pi>& a){
		sort(ALL(a),cmp);

		int gradmin=INF;

		vector<pi> res;
		REP(i,a.size()){
			if(a[i].fr>=gradmin) continue;
			pi cur=a[i];
			if(res.size()<=1) res.pb(cur);
			else{
				while(res.size()>=2){
					if(cross(res[res.size()-2],res.back())>=cross(res.back(),cur)){
						res.pop_back();
					}else break;
				}
				res.pb(cur);
			}
			chmin(gradmin,(int)a[i].fr);
		}
		a=res;
	}
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
		
		REP(i,n_) val[i+n-1].pb(ar2[i]);

		for(int i=n-2;i>=0;--i){
			val[i].insert(val[i].end(),ALL(val[i*2+1]));
			val[i].insert(val[i].end(),ALL(val[i*2+2]));

			fix(val[i]);
		}
	}

	lint getval(const vector<pi>& a,lint T){
		int lb=0,ub=a.size();
		while(ub-lb>1){
			int md=(lb+ub)>>1;
			if(cross(a[md-1],a[md])>T) ub=md;
			else lb=md;
		}
		return a[lb].fr*T+a[lb].sc;
	}

	lint query(int a,int b,int i,int l,int r,int T){
		if(a<=l && r<=b){
			return getval(val[i],T);
		}
		if(b<=l || r<=a) return INF2;
		int md=(l+r)>>1;
		return min(query(a,b,i*2+1,l,md,T),query(a,b,i*2+2,md,r,T));
	}
};
segtree seg;

int latsum[100005];
int main(){
	cin>>n;
	REP(i,n) scanf("%d",&ar[i]);

	for(int i=n-1;i>=0;--i) latsum[i]=latsum[i+1]+ar[i];


	for(int i=n-1;i>=0;--i){
		ar2[i].sc=latsum[i+1];
		ar2[i].fr=ar[i];
	}
	REP(i,n){
		ar2[i].sc-=(n-i-1)*ar[i];
	}


	seg.init(n);



	int q;cin>>q;
	REP(hoge,q){
		int x,y;scanf("%d%d",&y,&x);--x;--y;
		
		int d=n-1-x;


		int l=x-y,r=x+1;//[l...r)
		x+=d;y+=d;

		lint res=seg.query(l,r,0,0,seg.n,y+1);
		res-=latsum[r];
		cout<<res<<endl;
	}
	return 0;
}
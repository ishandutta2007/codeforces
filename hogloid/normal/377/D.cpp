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

//const int INF=5e8;

struct segtree{
	int lazy[1200005];
	pi maxi[1200005];
	int n;
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n) maxi[i+n-1].sc=i;
		for(int i=n-2;i>=0;--i) maxi[i].sc=maxi[i*2+1].sc;
	}
	void add(int a,int b,int i,int l,int r,int v){
		if(a<=l && r<=b){
			lazy[i]+=v;
			maxi[i].fr+=v;
			return;
		}
		if(b<=l || r<=a) return;
		int md=(l+r)>>1;
		if(lazy[i]){
			lazy[i*2+1]+=lazy[i];
			lazy[i*2+2]+=lazy[i];
			maxi[i*2+1].fr+=lazy[i];
			maxi[i*2+2].fr+=lazy[i];
			lazy[i]=0;
		}

		add(a,b,i*2+1,l,md,v);
		add(a,b,i*2+2,md,r,v);
		maxi[i]=max(maxi[i*2+1],maxi[i*2+2]);
	}
	pi query(){
		return maxi[0];
	}
};

segtree seg;

int n;
pair<pi,pi> eve[200005];
pair<pi,int> work[100005];
int main(){
	cin>>n;
	REP(i,n){
		int l,v,r;scanf("%d%d%d",&l,&v,&r);
		work[i]=mp(mp(l,r),v);
		eve[i*2]=mp(mp(l,1),mp(v,r));
		eve[i*2+1]=mp(mp(v+1,-1),mp(v,r));
	}
	seg.init(300002);
	
	int m=n*2;
	sort(eve,eve+m);
	int res=0,L,R;
	REP(i,m){
		int p=eve[i].fr.fr;
		int j=i;
		while(j<m && eve[j].fr.fr==p){
			dump(j);dump(eve[j]);
			seg.add(eve[j].sc.fr,eve[j].sc.sc+1,0,0,seg.n,eve[j].fr.sc);
			++j;
		}
		pi maxi=seg.query();
		dump(maxi);
		if(res<maxi.fr){
			res=maxi.fr;
			L=p;
			R=maxi.sc;
		}
		i=j-1;
	}
	dump(L);dump(R);
	cout<<res<<endl;
	REP(i,n){
		if(work[i].fr.fr<=L && L<=work[i].sc && work[i].sc<=R && R<=work[i].fr.sc){
			printf("%d\n",i+1);
		}
	}





	








	return 0;
}
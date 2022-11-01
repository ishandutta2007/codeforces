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
const int INF=5e8;
struct segtree{
	static const int MAX_N=400005;
	vector<pi> val[MAX_N];//[lef...rig)
	vector<int> latmin[MAX_N];
	vector<int> nxt[MAX_N];
	int n;
	void init(int n_,pi *a,int* ar){//(rig,lef)
		n=1;
		while(n<n_) n<<=1;
		REP(i,n_){
			val[i+n-1].pb(a[i]);
			nxt[i+n-1].pb(ar[i]);
		}
		for(int i=n-2;i>=0;--i){
			val[i].resize(val[i*2+1].size()+val[i*2+2].size());
			nxt[i].resize(nxt[i*2+1].size()+nxt[i*2+2].size());

			merge(ALL(val[i*2+1]),ALL(val[i*2+2]),val[i].begin());
			merge(ALL(nxt[i*2+1]),ALL(nxt[i*2+2]),nxt[i].begin());
		}

		REP(i,n*2){
			latmin[i].resize(val[i].size()+1);
			latmin[i][val[i].size()]=INF;
			for(int j=((int)val[i].size())-1;j>=0;--j){
				latmin[i][j]=min(latmin[i][j+1],val[i][j].sc);
			}
		}
	}
	bool query(int a,int b,int i,int l,int r){//[lef...rig)
		if(a<=l && r<=b){
			int p=lower_bound(ALL(val[i]),mp(b,-INF*2))-val[i].begin();
			int L=latmin[i][p];
			dump(p);
			if(L<=a) return true;
			return false;
		}

		if(b<=l || r<=a) return false;
		int md=(l+r)>>1;
		return (query(a,b,i*2+1,l,md) || query(a,b,i*2+2,md,r));
	}
	int kind(int a,int b,int i,int l,int r){
		if(a<=l && r<=b){
			return nxt[i].end()-lower_bound(ALL(nxt[i]),b);
		}
		if(b<=l || r<=a) return 0;
		int md=(l+r)>>1;
		return kind(a,b,i*2+1,l,md)+kind(a,b,i*2+2,md,r);
	}
};
segtree seg;
int n;
int ar[100005];

vector<int> num[100005];

int nxt[100005],dif[100005];

pi range[100005];
int main(){
	cin>>n;
	REP(i,n){
		scanf("%d",&ar[i]);
		num[ar[i]].pb(i);
	}
	for(int i=1;i<=100000;++i){
		for(int j=((int)num[i].size())-1;j>=0;--j){

			if(j==num[i].size()-1){
				nxt[num[i][j]]=INF;
				dif[num[i][j]]=-1;
				range[num[i][j]].sc=INF;
			}
			else{
				int p=num[i][j],q=num[i][j+1];
				nxt[p]=q;
				dif[p]=q-p;

				if(dif[q]==-1 || dif[p]==dif[q]){
					range[p].sc=range[q].sc;
				}else range[p].sc=nxt[q];
				range[q].fr=p+1;
			}
			if(j==0) range[num[i][j]].fr=-INF;
		}
	}
	REP(i,n) swap(range[i].fr,range[i].sc);
	seg.init(n,range,nxt);


	int q;scanf("%d",&q);
	REP(hoge,q){
		int l,r;scanf("%d%d",&l,&r);--l;

		int kind=seg.kind(l,r,0,0,seg.n);
		bool able=seg.query(l,r,0,0,seg.n);

		if(!able) ++kind;
		printf("%d\n",kind);
	}


	return 0;
}
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
//
struct BIT{
	lint val[4][1100][1100];
	int n;
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
		REP(d,4) REP(j,n+1) REP(i,n+1) val[d][j][i]=0;
	}
	void add(int k,int l,lint a){
		int d=(k&1)*2+(l&1);
		k>>=1;l>>=1;
		++k;++l;

		while(k<=n){
			int l2=l;
			while(l2<=n){
				val[d][k][l2]^=a;
				l2+=l2&-l2;
			}
			k+=k&-k;
		}
	}
	lint query(int k,int l){	//[0,k)
		int d=((k^1)&1)*2+((l^1)&1);
		k=(k+1)/2;l=(l+1)/2;
		lint res=0;
		while(k>0){
			int l2=l;
			while(l2>0){
				res^=val[d][k][l2];
				l2-=l2&-l2;
			}
			k-=k&-k;
		}
		return res;
	}
};
BIT bit;

int n,m;
int main(){

	cin>>n>>m;
	bit.init(n);
	REP(i,m){
		int t,x0,y0,x1,y1;scanf("%d%d%d%d%d",&t,&x0,&y0,&x1,&y1);
		--x0;--y0;
		int X[2]={x0,x1},Y[2]={y0,y1};
		if(t==1){
			lint res=0;
			REP(t,2) REP(s,2) res^=bit.query(X[t],Y[s]);
			printL(res);putchar('\n');
		}else{
			lint a=readL();
			REP(t,2) REP(s,2) bit.add(X[t],Y[s],a);
		}
	}


	return 0;
}
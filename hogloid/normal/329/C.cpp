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


int n,m;
pi es[100005];


pi es2[100005];
int perm[100005];
int main(){
	cin>>n>>m;

	REP(i,m){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		if(a>b) swap(a,b);
		es[i]=mp(a,b);
	}
	sort(es,es+m);

	REP(i,n) perm[i]=i;
	
	clock_t st=clock(),en;
	while((en=clock())-st<=1.3*CLOCKS_PER_SEC){
		random_shuffle(perm,perm+n);
		int m2=0;
		REP(i,n){
			int a=perm[i],b=perm[(i+1)%n];
			if(a>b) swap(a,b);
			if(binary_search(es,es+m,mp(a,b))){
			}else{
				es2[m2++]=mp(a,b);
			}
		}
		if(m2>=m){
			REP(i,m){
				printf("%d %d\n",es2[i].fr+1,es2[i].sc+1);
			}
			return 0;
		}
	}
	puts("-1");
	return 0;
}
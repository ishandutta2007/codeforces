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
vector<pair<pi,int> >col[7005];


int sets[10005],scnt;

void check(int i,int l,int r){
	REP(j,col[i].size()){
		if(r<=col[i][j].fr.fr || col[i][j].fr.sc<=l) ;
		else sets[scnt++]=col[i][j].sc;
	}
}
int getleft(int i,int l){
	int exp=1,cnt=0;
	while(exp<l){
		exp<<=1;
		++cnt;
	}
	return l+cnt;
}
int getright(int i,int l){
	int exp=1,cnt=0;
	while(exp<=l){
		exp<<=1;
		++cnt;
	}
	return l+cnt;
}
int main(){
	cin>>n>>m;
	REP(hoge,m){
		int t;scanf("%d",&t);
		if(t==1){
			int lev,l,r,x;scanf("%d%d%d%d",&lev,&l,&r,&x);
			++r;
			col[lev].pb(mp(mp(l,r),x));
		}else{
			int lev,v;scanf("%d%d",&lev,&v);
			scnt=0;
			int l=v,r=v+1;
			for(int i=lev;i<=n;++i){
				dump(i);
				dump(l);dump(r);
				check(i,l,r);
				l=getleft(i,l);
				r=getright(i,r-1)+1;
			}
			sort(sets,sets+scnt);
			scnt=unique(sets,sets+scnt)-sets;
			debug(sets,sets+scnt);

			printf("%d\n",scnt);
		}
	}

	return 0;
}
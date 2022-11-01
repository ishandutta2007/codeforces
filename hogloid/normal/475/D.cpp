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

int n;
int ar[100005];

map<int,lint> cnt;

void rec(int l,int r){

	if(r-l==1){
		cnt[ar[l]]++;
		return ;
	}

	int md=(l+r)>>1;
	rec(l,md);
	rec(md,r);
	
	int g=ar[md],st=md;
	vector<pi> right,left;
	for(int i=md;i<r;++i){
		if(g==__gcd(ar[i],g)) ;
		else{
			right.pb(mp(g,i-st));
			st=i;
			g=__gcd(ar[i],g);
		}
	}
	right.pb(mp(g,r-st));
	
	g=ar[md-1];
	st=md-1;
	for(int i=md-1;i>=l;--i){
		if(g==__gcd(ar[i],g)) ;
		else{
			left.pb(mp(g,st-i));
			st=i;
			g=__gcd(ar[i],g);
		}
	}
	left.pb(mp(g,st-l+1));
	debug(ALL(right));
	debug(ALL(left));


	REP(i,right.size()) REP(j,left.size()){
		int g=__gcd(right[i].fr,left[j].fr);
		cnt[g]+=right[i].sc*(lint)left[j].sc;
	}
}


int main(){
	cin>>n;
	REP(i,n){
		scanf("%d",&ar[i]);
	}
	rec(0,n);

	prl;
	int q;scanf("%d",&q);
	REP(hoge,q){
		int a;scanf("%d",&a);
		lint res=0;
		if(cnt.count(a)) res=cnt[a];

		printL(res);
		putchar('\n');
	}




	return 0;
}
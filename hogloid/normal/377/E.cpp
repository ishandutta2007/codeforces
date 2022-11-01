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

//const int INF=5e8;

int n;
lint s;
pi mach[200005];


bool cmp(const pi&a,const pi&b){
	return mp(a.fr,-a.sc)<mp(b.fr,-b.sc);
}

lint getX(pi a,pi b){//starting point of B
	return (a.sc-b.sc+b.fr-a.fr-1)/(b.fr-a.fr);
}
pi stk[200005];

int m;
int getpiv(lint cost){
	int lb=-1,ub=m-1;
	while(ub-lb>1){
		int md=(lb+ub)>>1;
		lint R;
		R=getX(stk[md],stk[md+1]);
		lint up=(R-1)*stk[md].fr+stk[md].sc;
		if(cost<=up) ub=md;
		else lb=md;
	}
	return ub;
}

int main(){
	cin>>n>>s;
	REP(i,n){
		int a,b;scanf("%d%d",&a,&b);
		mach[i]=mp(a,b);
	}

	sort(mach,mach+n,cmp);
	
	m=0;
	REP(i,n){
		while(m>0 && mach[m-1].sc>=mach[i].sc) --m;
		mach[m++]=mach[i];
	}

	n=m;
	m=0;
	REP(i,n){
		if(i==0) {
			stk[m++]=mp(mach[i].fr,0);
		}else{
			int piv=getpiv(mach[i].sc);
			lint time=(mach[i].sc-stk[piv].sc+stk[piv].fr-1)/stk[piv].fr;
			lint rest=time*stk[piv].fr+stk[piv].sc-mach[i].sc;

			pi push=mp(mach[i].fr,rest-time*mach[i].fr);

			while(m>1 && getX(stk[m-2],stk[m-1])>=getX(stk[m-1],push)){
				--m;
			}
			stk[m++]=push;
		}
	}
	
	int piv=getpiv(s);

	lint time=(s-stk[piv].sc+stk[piv].fr-1)/stk[piv].fr;
	cout<<time<<endl;




	return 0;
}
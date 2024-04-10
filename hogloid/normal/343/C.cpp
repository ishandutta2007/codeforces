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

lint h[100005],pos[100005];

bool ok(lint l,lint r,lint st,lint len){
	lint cost;
	if(l<=st && st<=r) cost=min(r-st,st-l)+r-l;
	else if(st<l) cost=r-st;
	else cost=st-l;

	return cost<=len;
}

int main(){
	cin>>n>>m;

	REP(i,n){
		h[i]=readL();
	}
	REP(i,m){
		pos[i]=readL();
	}
	
	lint lb=-1,ub=1e12;
	while(ub-lb>1){
		lint md=(lb+ub)>>1;
		
		int cur=0;
		REP(i,n){
			int j=cur;
			while(ok(pos[cur],pos[j],h[i],md) && j<m) ++j;

			cur=j;
		}
		if(cur==m) ub=md;
		else lb=md;
	}
	cout<<ub<<endl;

	return 0;
}
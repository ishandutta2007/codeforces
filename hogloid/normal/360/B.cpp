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


int n,k;
lint ar[2005];

bool g[2005][2005];

int maxi[2005];
int main(){
	cin>>n>>k;
	REP(i,n) cin>>ar[i];

	lint lb=-1,ub=2.2e9;

	while(ub-lb>1){
		lint md=(lb+ub)>>1;
		
		CLR(g);
		REP(i,n) REPN(j,n,i+1){
			if(abs(ar[i]-ar[j])<=md*(j-i)) g[i][j]=1;
		}
	

		int suc=0;
		REP(i,n){
			maxi[i]=1;
			REP(j,i) if(g[j][i]) chmax(maxi[i],maxi[j]+1);

			if(maxi[i]>=n-k){
				suc=1;
			}
		}
		dump(md);
		debug(maxi,maxi+n);
		if(suc) ub=md;
		else lb=md;
	}

	cout<<ub<<endl;




	return 0;
}
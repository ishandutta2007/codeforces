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
int g[1005][1005];
int main(){
	int k;cin>>k;
	int n=2+60+90;
	
	REP(i,30){
		g[i*2+2][i*2+3]=1;
		if(i<29) g[i*2+3][i*2+4]=1;
	}
	g[61][1]=1;

	int add=62;
	int last=0;
	REP(i,30){
		g[last][add+i*3]=g[last][add+i*3+1]=1;
		g[add+i*3][add+i*3+2]=g[add+i*3+1][add+i*3+2]=1;

		last=add+i*3+2;
	}

	REP(i,30) if(k>>i&1){
		if(i==0) g[0][2]=1;
		else g[add+i*3-1][i*2+2]=1;
	}


	cout<<n<<endl;
	REP(i,n){
		REP(j,n) putchar(g[i][j] || g[j][i]?'Y':'N');
		putchar('\n');
	}



	return 0;
}
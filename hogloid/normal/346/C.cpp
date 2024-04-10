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

const int INF=1e9+10;

int n;
int x[100005];

int mov[1000005];
int A,B;
int main(){
	cin>>n;
	REP(i,n) scanf("%d",&x[i]);

	sort(x,x+n);
	n=unique(x,x+n)-x;

	cin>>A>>B;
	REP(i,A-B+1) mov[i]=INF;

	REP(i,n){
		for(int j=(B+x[i]-1)/x[i]*x[i];j<A;j+=x[i]){
			int indx=min(A,j+x[i]-1);
			indx-=B;
			chmin(mov[indx],j-B);
		}
	}

	for(int i=A-B;i>0;--i){
		chmin(mov[i-1],mov[i]);
		chmin(mov[i],i-1);
	}

	int res=0;
	int cur=A-B;
	while(cur>0){
		cur=mov[cur];
		++res;
	}
	cout<<res<<endl;

	return 0;
}
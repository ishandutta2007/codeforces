#define DEB

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#ifdef DEB
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


int n;
int ar[100005];

vector<int> inv;
int main(){
	cin>>n;
	REP(i,n) scanf("%d",&ar[i]);
	
	if(n<=2){
		printf("%d\n",n);
		return 0;
	}
	
	inv.pb(-1);
	REPN(i,n,1){
		if(ar[i-1]>=ar[i]){
			inv.pb(i-1);
		}
	}

	
	int res=2;

	inv.pb(n-1);

	if(inv.size()==2) res=n;
	REPN(i,inv.size()-1,1){
		int p=inv[i];
		int okl=0,okr=0;

		if(p==0 || ar[p+1]-ar[p-1]>=2) okl=1;

		if(p==n-2 || ar[p+2]-ar[p]>=2) okr=1;
		
		if(okl || okr){
			chmax(res,inv[i+1]+1-(inv[i-1]+1));
		}else{
			chmax(res,inv[i+1]+1-p);
			chmax(res,p+2-(inv[i-1]+1));
		}
	}



	cout<<res<<endl;
	return 0;
}
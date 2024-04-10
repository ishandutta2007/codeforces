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
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;
int n,m;
int price[105],mark[105];
int ar2[105];
int main(){
	cin>>n>>m;
	REP(i,n) cin>>price[i];
	REP(i,m){
		int a;cin>>a;--a;
		mark[a]=1;
		ar2[i]=price[a];
	}

	lint res=0;
	REP(i,n) if(!mark[i]) res+=price[i];
	sort(ar2,ar2+m,greater<int>());

	REP(i,m){
		if(res<=ar2[i]) res+=ar2[i];
		else res*=2;
	}
	cout<<res<<endl;


	return 0;
}
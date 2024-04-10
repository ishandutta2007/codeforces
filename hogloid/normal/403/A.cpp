#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<set>
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

int t,n,p;
set<pi> es;
int main(){
	cin>>t;
	while(t--){
		es.clear();
		cin>>n>>p;
		REP(i,n) REP(j,i) es.insert(mp(j,i));

		REP(i,n){
			int a=i,b=(i+1)%n;
			if(a>b) swap(a,b);
			printf("%d %d\n",a+1,b+1);
			es.erase(mp(a,b));
		}
			
		REP(i,n){
			int a=i,b=(i+2)%n;
			if(a>b) swap(a,b);
			printf("%d %d\n",a+1,b+1);
			es.erase(mp(a,b));
		}

		auto it=es.begin();
		REP(hoge,p){
			printf("%d %d\n",it->fr+1,it->sc+1);
			++it;
		}
	}
	return 0;
}
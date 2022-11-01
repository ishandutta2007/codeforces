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

lint n,k;
int d[100005];
vector<int> each[100005];
vector<pi> res;
bool solve(){
	if(each[0].size()!=1) return false;
	lint ever=1;
	for(int i=1;ever<n;++i){
		lint coef=k-1;
		if(i==1) coef=k;
		if(each[i].size()>coef*each[i-1].size() || each[i].size()==0) return false;

		REP(j,each[i].size()){
			res.pb(mp(each[i-1][j/coef],each[i][j]));
		}
		ever+=each[i].size();
	}
	return true;
}


int main(){
	cin>>n>>k;
	REP(i,n){
		cin>>d[i];
		each[d[i]].pb(i);
	}
	if(solve()==false){
		puts("-1");
		return 0;
	}
	printf("%d\n",res.size());
	REP(i,res.size()){
		printf("%d %d\n",res[i].fr+1,res[i].sc+1);
	}




	return 0;
}
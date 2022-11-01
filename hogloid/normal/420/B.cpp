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
pi event[100005];
int mark[100005];

int can[100005];

int main(){
	cin>>n>>m;
	REP(i,m){
		char tmp[5];
		int a;
		scanf("%s%d",tmp,&a);--a;
		event[i]=mp(a,(tmp[0]=='+'?1:-1));
		if(mark[a]==0) mark[a]=(tmp[0]=='+'?1:-1);
	}
	vector<int> res;
	REP(i,n){
		if(mark[i]==0){
			res.pb(i);
		}else can[i]=1;
	}

	int cur=0;
	REP(i,n){
		if(mark[i]==-1) ++cur;
	}
	if(cur) REP(i,n) if(mark[i]==1) can[i]=0;

	int canflag=-1;
	REP(i,m){
		if(event[i].sc==1){
			++cur;
			if(cur==1){
				if(canflag==-1) canflag=event[i].fr;
				else if(canflag!=event[i].fr) canflag=-2;
			}
		}else {
			--cur;
			int who=event[i].fr;
			if(cur) can[who]=0;
		}
	}
	
	if(canflag==-1){
		REP(i,n) if(can[i]) res.pb(i);
	}else if(canflag>=0){
		if(can[canflag]) res.pb(canflag);
	}

	sort(ALL(res));
	cout<<res.size()<<endl;
	REP(i,res.size()) printf("%d%c",res[i]+1,i==res.size()-1?'\n':' ');



	return 0;
}
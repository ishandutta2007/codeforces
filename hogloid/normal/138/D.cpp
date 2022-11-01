#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define ALL(t) (t).begin(),(t).end()
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
int h,w;
char buf[25][25];
char map[2][50][50];
int memo[2][25][25][25][25];
int rec(int t,int u,int l,int b,int r){
	if(u>=b || r<=l) return 0;
	int& res=memo[t][u][l][b][r];
	if(res!=-1) return res;
	vector<int> tmp;
	REPN(i,b,u) REPN(j,r,l) if(map[t][i][j]){
		if(map[t][i][j]=='X'){
			tmp.pb(rec(t,u,l,i,j)^rec(t,u,j+1,i,r)^rec(t,i+1,l,b,j)^rec(t,i+1,j+1,b,r));
		}else if(map[t][i][j]=='L'){
			tmp.pb(rec(t,u,l,i,r)^rec(t,i+1,l,b,r));
		}else if(map[t][i][j]=='R'){
			tmp.pb(rec(t,u,l,b,j)^rec(t,u,j+1,b,r));
		}
	}
	res=0;
	sort(ALL(tmp));
	int sz=unique(ALL(tmp))-tmp.begin();
	while(res<sz && tmp[res]==res) ++res;
	return res;
}

int main(){
	cin>>h>>w;
	REP(i,h) scanf("%s",buf[i]);
	REP(i,h) REP(j,w){
		map[(i+j)&1][(i+j)/2][(i-j+w)/2]=buf[i][j];
	}
	memset(memo,-1,sizeof(memo));
	int a=rec(0,0,0,20,20),b=rec(1,0,0,20,20);

	if(a^b) puts("WIN");
	else puts("LOSE");
	return 0;
}
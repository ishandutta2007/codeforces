#include<iostream>
#include<algorithm>
#include<cstdio>
#include<bitset>
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
int h,w,q;
char buf[505][505];
int ans[1000005];
struct query_{
	int y1,x1,y2,x2;
	int id;
};
bitset<505> able[2][505][505];
void rec(int l,int r,vector<query_>& query){
	vector<query_>left,right;
	int md=(l+r)>>1;
	
	REP(i,h) REPN(j,r,l) able[0][i][j].reset(),able[1][i][j].reset();
	REP(i,h) if(buf[i][md]=='.') able[0][i][md].set(i),able[1][i][md].set(i);
	for(int i=h-1;i>=0;--i) for(int j=md;j>=l;--j) if(buf[i][j]=='.'){
		able[0][i][j]|=able[0][i+1][j];
		if(j<md) able[0][i][j]|=able[0][i][j+1];
	}

	REP(i,h) REPN(j,r,md) if(buf[i][j]=='.'){
		if(buf[i][j+1]=='.') able[1][i][j+1]|=able[1][i][j];
		if(buf[i+1][j]=='.') able[1][i+1][j]|=able[1][i][j];
	}

	REP(i,query.size()){
		if(query[i].x1<=md && md<=query[i].x2){
			if((able[0][query[i].y1][query[i].x1]&
				able[1][query[i].y2][query[i].x2]).any()){
				ans[query[i].id]=1;
			}
		}else if(query[i].x2<md) left.pb(query[i]);
		else right.pb(query[i]);
	}
	if(!left.empty()) rec(l,md,left);
	if(!right.empty()) rec(md,r,right);
	query.clear();
}

int main(){
	REP(i,h) REP(j,w) buf[i][j]='#';
	scanf("%d%d",&h,&w);
	REP(i,h) scanf("%s",buf[i]);
	scanf("%d",&q);
	vector<query_> query;
	REP(i,q){
		int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
		--a;--b;--c;--d;
		if(a>c || b>d) continue;
		query.pb((query_){a,b,c,d,i});
	}
	rec(0,w,query);
	REP(i,q){
		if(ans[i]) puts("Yes");
		else puts("No");
	}
		
	return 0;
}
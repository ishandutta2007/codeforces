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
int buf[105][105];
int flip[2][105];
int main(){
	cin>>h>>w;
	REP(i,h) REP(j,w) cin>>buf[i][j];
	
	int flag=1;
	while(flag){
		flag=0;
		REP(i,h){
			int sum=0;
			REP(j,w) sum+=buf[i][j];
			if(sum<0){
				REP(j,w) buf[i][j]=-buf[i][j];
				flag=1;
				flip[0][i]^=1;
			}
		}
		REP(i,w){
			int sum=0;
			REP(j,h) sum+=buf[j][i];
			if(sum<0){
				REP(j,h) buf[j][i]=-buf[j][i];
				flag=1;
				flip[1][i]^=1;
			}
		}
	}
	vector<int> r,c;
	REP(i,h) if(flip[0][i]) r.pb(i);
	REP(i,w) if(flip[1][i]) c.pb(i);
	printf("%d",(int)r.size());
	REP(i,r.size()) printf(" %d",r[i]+1);
	putchar('\n');

	printf("%d",(int)c.size());
	REP(i,c.size()) printf(" %d",c[i]+1);
	putchar('\n');



	return 0;
}
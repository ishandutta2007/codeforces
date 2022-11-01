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
int n;
int c[55];
int buf[55][55];
int m;
pair<pi,pi> res[3000];
int main(){
	cin>>n;
	REP(i,n) cin>>c[i];
	REP(i,n) REP(j,c[i]) cin>>buf[i][j];

	REP(i,n) REP(j,c[i]){
		int mini=INF,y,x;
		REP(i2,n) REP(j2,c[i2]){
			if(mp(i2,j2)>=mp(i,j) && mini>buf[i2][j2]){
				mini=buf[i2][j2];
				y=i2;x=j2;
			}
		}
		if(mp(y,x)==mp(i,j)) continue;
		res[m]=mp(mp(i,j),mp(y,x));
		swap(buf[i][j],buf[y][x]);
		++m;
	}
	printf("%d\n",m);
	REP(i,m) printf("%d %d %d %d\n",res[i].fr.fr+1,res[i].fr.sc+1,res[i].sc.fr+1,res[i].sc.sc+1);


	return 0;
}
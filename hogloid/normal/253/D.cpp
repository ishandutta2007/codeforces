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
int n,m,k;
char buf[405][405];
int sum[405][405];
int cnt[30];
int event[30][405];
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	REP(i,n) scanf("%s",buf[i]);
	REP(i,n) REP(j,m) sum[i+1][j+1]=sum[i][j+1]+sum[i+1][j]-sum[i][j]+(buf[i][j]=='a'?1:0);
	
	lint res=0;
	REP(i,m) REPN(j,m,i+1){
		memset(cnt,0,sizeof(cnt));
		REP(y,n) if(buf[y][i]==buf[y][j]){
			event[buf[y][i]-'a'][cnt[buf[y][i]-'a']++]=y;
		}
		REP(c,26){
			int y2=0;
			REP(y,cnt[c]){
				while(y2<cnt[c] && sum[event[c][y2]+1][j+1]-sum[event[c][y2]+1][i]
							-sum[event[c][y]][j+1]+sum[event[c][y]][i]<=k){
					++y2;
				}
				y2=max(y2,y+1);
				res+=y2-y-1;
			}
		}
	}
	cout<<res<<endl;
	return 0;
}
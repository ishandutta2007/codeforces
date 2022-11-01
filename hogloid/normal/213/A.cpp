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
int c[205];
int rev[205][205];
int need[205][205],K[205],prev[205];
int done[205];
int main(){
	scanf("%d",&n);
	REP(i,n) scanf("%d",&c[i]),--c[i];
	REP(i,n){
		int k;scanf("%d",&k);
		prev[i]=K[i]=k;
		REP(j,k){
			int a;scanf("%d",&a);--a;
			need[i][a]=1;
			rev[a][i]=1;
		}
	}
	int res=INF;
	REP(hoge,3){
		memset(done,0,sizeof(done));
		int pos=hoge;
		int tmp=0;
		int cnt=0;
		REP(i,n) K[i]=prev[i];
		while((int)count(done,done+n,0)>0){
			REP(hoge2,n+1){
			REP(i,n) if(!done[i] && c[i]==pos){
				if(K[i]==0){
					++tmp;
					done[i]=1;
					REP(j,n) if(rev[i][j]) --K[j];
				}
			}
			}
			++tmp;
			pos=(pos+1)%3;
		}
		--tmp;
		res=min(res,tmp);
	}
	cout<<res<<endl;


	return 0;
}
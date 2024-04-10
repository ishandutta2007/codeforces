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
int n,k;
int g[2005][2005];
int main(){
	cin>>n>>k;
	REP(i,n) REPN(j,n,i+1){
		scanf("%d",&g[i][j]);
		g[j][i]=g[i][j];
	}
	REP(i,n) g[i][i]=-1;
	
	double res=0;
	if(k==1 || k>=3){
		REP(i,n) REP(j,n) if(g[i][j]!=-1) res+=g[i][j];
		res/=n;
	}else{

		REP(i,n){
			int deg=0;
			double tmp=0;
			REP(j,n) if(g[i][j]!=-1) ++deg;
			REP(j,n) if(g[i][j]!=-1){
				tmp+=g[i][j];
			}
			if(deg>=2){
				tmp*=deg-1;
				tmp*=2;
				res+=tmp;
			}
		}
		res/=n*(lint)(n-1);
	}
	cout<<(lint)res<<endl;
	return 0;
}
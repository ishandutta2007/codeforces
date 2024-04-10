#include<cstdio>
#include<algorithm>
#include<set>
#include<stack>
#include<iomanip>
#include<numeric>
#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
#include<string>
#include<map>
#include<queue>
#define REP(i,maxi) for(int i=0;i<maxi;++i)
#define INF ((int)1e9)
#define REPN(i,maxi,init) for(int i=init;i<maxi;++i)
#define FOR(it,t) for(__typeof(t) it=(t).begin();it!=(t).end();++it)
#define ALL(t) t.begin(),t.end()
#define dump(x) cout<<#x<<" = "<<(x)<<endl;
#define prl cout<<"LINE "<<__LINE__<<" is called"<<endl;
#define mp make_pair
#define sc second
#define fr first
#define pb push_back
using namespace std;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pair<int,int> > vp;		//[[iwi]] [[[{(iwiwiwiwiwiwiwiwiwiwiwiwi)}]]
static const double PI=atan(-1.0);
int n,k,a;
vi per;
double res=0;
vp g,tg;
void dfs(int dep,int sum){
	if(dep==n){
		if(sum!=k) return;
		g=tg;
		REP(i,n){
			g[i].sc+=10*per[i];
			if(g[i].sc>100)g[i].sc=100; 
		}
		int bit2=(1<<n);
		double probsum=0;
		REP(j,bit2){
			double prob=1.0;
			long long int sum=0;
			int get=0;
			REP(k,n){
				if(j>>k&1) {++get;prob*=g[k].sc/100.0;}
				else{
					prob*=(100-g[k].sc)/100.0;
					sum+=g[k].fr;
				}
			}
			if(n&1){
				if(get<n/2+n%2)
				prob*=(double)a/(a+sum);
			}else if(get<=n/2) prob*=(double)a/(a+sum);
			probsum+=prob;
		}
		res=max(res,probsum);
		return;
	}
	REP(i,k+1){
		if(sum+i>k) break;
		per[dep]=i;
		dfs(dep+1,sum+i);
	}
}
int main(){
	scanf("%d%d%d",&n,&k,&a);
	g.resize(n);
	REP(i,n) scanf("%d%d",&g[i].fr,&g[i].sc);
	tg=g;per.resize(n);
	dfs(0,0);
	printf("%.9f\n",res);
	return 0;
}
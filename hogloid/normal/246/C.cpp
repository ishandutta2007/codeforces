#include<iostream>
#include<algorithm>
#include<set>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define FOR(it,t) for(__typeof((t).begin()) it=(t).begin();it!=(t).end();++it)
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
set<pair<int,vector<int> > > dp[55];
set<int> dp2[55];
int n,k;
int a[55];
set<pair<int,vector<int> > >res;
int main(){
	cin>>n>>k;
	REP(i,n) cin>>a[i];
	dp2[0].insert(0);
	dp[0].insert(mp(0,vector<int>(0)));
	REP(i,n+1){
		if(dp[i].size()>k){
			res=dp[i];
			break;
		}
		FOR(it,dp[i]){
			pair<int,vector<int> >tmp=(*it);
			if(dp2[i+1].count(tmp.fr)==0){
				dp[i+1].insert(tmp);
				dp2[i+1].insert(tmp.fr);
			}

			tmp.sc.pb(a[i]);
			tmp.fr+=a[i];
			if(dp2[i+1].count(tmp.fr)==0){
				dp[i+1].insert(tmp);
				dp2[i+1].insert(tmp.fr);
			}
		}
	}
	int cnt=0;
	FOR(it,res) if(it->fr>0){
		printf("%d",(int)it->sc.size());
		REP(i,it->sc.size()) printf(" %d",it->sc[i]);
		putchar('\n');
		++cnt;
		if(cnt>=k) break;
	}

	return 0;
}
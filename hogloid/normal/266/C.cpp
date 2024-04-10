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
pi p[1005];
int buf[1005][1005];
int rsum[1005];
int csum[1005][1005];
vector<pair<int,pi> >ans;
int main(){
	scanf("%d",&n);
	REP(i,n-1){
		scanf("%d%d",&p[i].fr,&p[i].sc);
		--p[i].fr;--p[i].sc;
		++rsum[p[i].fr];
	}
	for(int i=n-1;i>=1;--i) if(rsum[i]==0){
		for(int j=i-1;j>=0;--j) if(rsum[j]>0){
			ans.pb(mp(1,mp(i,j)));
			swap(rsum[i],rsum[j]);
			REP(k,n-1) if(p[k].fr==j) p[k].fr=i;
			break;
		}
	}

	REP(i,n-1){
		++buf[p[i].fr][p[i].sc];
	}
			
	REP(i,n) REP(j,n) csum[i+1][j]=csum[i][j]+buf[i][j];

	for(int i=n-1;i>=0;--i) if(csum[i+1][i]>0){
		REP(j,i) if(csum[i+1][j]==0){
			REP(k,n+1) swap(csum[k][i],csum[k][j]);
			ans.pb(mp(2,mp(i,j)));
			break;
		}
	}

	printf("%d\n",(int)ans.size());
	REP(i,ans.size()){
		printf("%d %d %d\n",ans[i].fr,ans[i].sc.fr+1,ans[i].sc.sc+1);
	}
		
	return 0;
}
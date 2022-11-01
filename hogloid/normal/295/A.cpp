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
int ar[100005];
lint imos[100005];
int cnt[100005];
pair<pi,int> ope[100005];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	REP(i,n) scanf("%d",&ar[i]);
	REP(i,m) scanf("%d%d%d",&ope[i].fr.fr,&ope[i].fr.sc,&ope[i].sc);

	REP(i,k){
		int a,b;scanf("%d%d",&a,&b);--a;
		cnt[a]++;
		cnt[b]--;
	}
	REP(i,m) cnt[i+1]+=cnt[i];
	
	REP(i,m){
		imos[ope[i].fr.fr-1]+=ope[i].sc*(lint)cnt[i];
		imos[ope[i].fr.sc]-=ope[i].sc*(lint)cnt[i];
	}
	REP(i,n) imos[i+1]+=imos[i];
	
	REP(i,n) cout<<imos[i]+ar[i]<<endl;

	return 0;
}
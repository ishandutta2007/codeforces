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
int pos[1005];
pi segs[1005];
int main(){
	cin>>n;
	REP(i,n) cin>>pos[i];
	REP(i,n-1){
		segs[i]=mp(pos[i],pos[i+1]);
		if(segs[i].sc<segs[i].fr) swap(segs[i].fr,segs[i].sc);
	}
	sort(segs,segs+n-1);
	int ok=0;
	REP(i,n-1) REPN(j,n-1,i+1) if(segs[j].fr<segs[i].sc && segs[j].sc>segs[i].sc
				 && segs[j].fr>segs[i].fr){
		ok=1;
	}
	if(ok) puts("yes");
	else puts("no");

	
	return 0;
}
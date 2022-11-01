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
pi ps[200005];
#include<set>
set<pi> ans;
int main(){
	scanf("%d%d",&n,&k);
	REP(i,n) scanf("%d%d",&ps[i].fr,&ps[i].sc);
	sort(ps,ps+n);
	
	if(n<=k) {
		puts("-1");
		return 0;
	}

	REP(i,k+1) REP(c,k+1){
		int j=n-1-c;
		pi p=mp(ps[i].fr+ps[j].fr,ps[i].sc+ps[j].sc);
		
		
		int j2=n-1,unmatch=0;
		REP(i2,n){
			pi want=mp(p.fr-ps[i2].fr,p.sc-ps[i2].sc);
			while(j2>=0 && ps[j2]>want) --j2;
			if(j2>=0 && ps[j2]==want);
			else ++unmatch;
		}

		if(unmatch>k) continue;
		ans.insert(p);
	}
	cout<<ans.size()<<endl;
	set<pi>::iterator it=ans.begin();
	while(it!=ans.end()){
		printf("%.2f %.2f\n",it->fr/2.0,it->sc/2.0);
		++it;
	}

	return 0;
}
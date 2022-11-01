#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define pb push_back
#define mp make_pair
#define fr first
#define ALL(t) (t).begin(),(t).end()
#define sc second
#define ITR(it) __typeof((it).begin())
#define FOR(itr,data) for(ITR(data) itr=(data).begin();itr!=(data).end();++itr)
#define INF ((int)5e8)
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define prl cerr<<"called:"<< __LINE__<<endl;
using namespace std;
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
map<string,int> score;
int main(){
	string tmp;
	int n;scanf("%d",&n);
	vector<int> all;
	REP(i,n){
		int a;cin>>tmp>>a;
		score[tmp]=max(score[tmp],a);
	}
	FOR(it,score) all.pb(it->sc);
	sort(ALL(all));
	int m=all.size();
	printf("%d\n",m);
	FOR(it,score){
		int a=it->sc;
		cout<<it->fr<<' ';
		int upper=(all.end()-upper_bound(ALL(all),a));
		if(upper*2>m) printf("noob\n");
		else if(upper*5>m) printf("random\n");
		else if(upper*10>m) printf("average\n");
		else if(upper*100>m) printf("hardcore\n");
		else printf("pro\n");
	}


	return 0;
}
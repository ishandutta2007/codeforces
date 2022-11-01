#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
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
vector<pair<pair<lint,lint>,int> > range;

int main(){
	range.pb(mp(mp(0,3),0));
	range.pb(mp(mp(4,15),1));
	range.pb(mp(mp(16,81),2));
	range.pb(mp(mp(82,6723),0));
	range.pb(mp(mp(6724,50625),3));
	range.pb(mp(mp(50626ll,2562991875ll),1));
	range.pb(mp(mp(2562991876ll,1e13),2));
	cin>>n;
	int sum=0;
	REP(i,n){
		lint a;cin>>a;
		REP(j,range.size()) if(range[j].fr.fr<=a && a<=range[j].fr.sc){
			sum^=range[j].sc;
		}
	}
	if(sum) puts("Furlo");
	else puts("Rublo");
	return 0;
}
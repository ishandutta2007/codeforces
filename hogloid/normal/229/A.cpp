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
char buf[110][10005];
int h,w;
vector<int> ones[110];
int main(){
	cin>>h>>w;
	REP(i,h) scanf("%s",buf[i]);
	REP(i,h) REP(j,w) if(buf[i][j]=='1'){
		ones[i].pb(j);
		ones[i].pb(j+w);
		ones[i].pb(j+w*2);
	}
	REP(i,h) sort(ALL(ones[i]));
	int res=INF;
	REP(i,w){
		int tmp=0;
		REP(j,h){
			if(ones[j].empty()){
				tmp=INF;break;
			}
			vector<int>::iterator it=lower_bound(ALL(ones[j]),i+w);
			int a=*it-(i+w),b;
			--it;
			b=i+w-(*it);
			tmp+=min(a,b);
		}
		res=min(res,tmp);
	}
	if(res>=INF) res=-1;
	printf("%d\n",res);

	return 0;
}
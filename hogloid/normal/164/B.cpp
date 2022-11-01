#include <string>
#include <vector>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<numeric>
#include<list>
#include<cstdio>
#include<set>
#include<map>
#include<cmath>
#include<cstring>
#define REP(num,num2) for(int num=0;num<(int)num2;++num)
#define REPN(num,num2,init) for(int num=init;num<(int)num2;++num)
#define ITR(x) __typeof((x).begin())
#define FOR(itr,data) for(ITR(data) itr=(data).begin();itr!=(data).end();++itr)
#define ALL(typ) (typ).begin(),(typ).end()
#define SPR(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz size()
#define INF ((int)1e9)
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define prl cerr<<"called:"<< __LINE__<<endl;
using namespace std;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
typedef long long int lint;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int,int> > vp;
typedef pair<int,int> pi;
const double PI  = acos(-1.0);
template<class T> void debug(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
int a[1000005],b[1000005];
int match[2000005];
pi sa[1000005],sb[1000005];
lint place[2000005];
int n,m;
lint getoverK(lint k,int i){
	if(k%m<match[i]) return match[i]+k/m*m;
	else return match[i]+k/m*m+m;
}
int main(){
	scanf("%d%d",&n,&m);
	REP(i,n) scanf("%d",&a[i]),sa[i]=mp(a[i],i);
	REP(i,m) scanf("%d",&b[i]),sb[i]=mp(b[i],i);
	sort(sa,sa+n);
	sort(sb,sb+m);
	
	REP(i,n){
		int p=lower_bound(sb,sb+m,mp(a[i],-1))-sb;
		if(p<m && sb[p].fr==a[i]) match[i]=sb[p].sc;
		else match[i]=-1;
	}
	REP(i,n) match[i+n]=match[i];
	
	int res=0,begin2=-1;
	lint begin,end;
	REP(i,n*2){
		if(match[i]==-1){
			begin2=-1;
			continue;
		}
		if(begin2==-1){
			begin=end=match[i];
			place[i]=match[i];
			res=max(res,1);
			begin2=i;
			continue;
		}
		lint nxt=getoverK(end,i);
		while(nxt-begin>=m){
			++begin2;
			begin=place[begin2];
		}
		place[i]=nxt;
		end=nxt;
		res=max(res,i-begin2+1);
	}
	printf("%d\n",res);


	return 0;
}
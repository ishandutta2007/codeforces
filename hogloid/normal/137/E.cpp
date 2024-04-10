#include<string>
#include<vector>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<numeric>
#include<list>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<cstdlib>
#include<cmath>
#define REP(num,num2) for(int num=0;num<(int)(num2);++num)
#define REPN(num,num2,init) for(int num=init;num<(int)(num2);++num)
#define FOR(itr,data) for(__typeof((data).begin()) itr=(data).begin();itr!=(data).end();++itr)
#define ITR(tp) __typeof((tp).begin())
#define SZ(t) ((int)t.size())
#define ALL(typ) (typ).begin(),(typ).end()
#define pb push_back
#define mp make_pair
#define EPS (1e-8)
#define RANGE(t,n) (t).begin(),(t).begin()+n
#define fr first
#define sc second
#define SPR(x) ((x)*(x))
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
typedef vector<string> vs;
const double PI  = acos(-1.0);
string s;
int sum[200005];
int latermin[200005];
int main(){
	cin>>s;
	int len=SZ(s);
	REP(i,len){
		if(s[i]>='A' && s[i]<='Z') s[i]=s[i]-'A'+'a';
	}
	sum[0]=0;
	REP(i,len){
		sum[i+1]=sum[i];
		if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') ++sum[i+1];
		else sum[i+1]-=2;
	}
	latermin[len+1]=INF;
	for(int i=len;i>=0;--i){
		latermin[i]=min(latermin[i+1],sum[i]);
	}
	int maxi=0,num=0;
	REP(i,len){
		int ub=len+1,lb=i;
		while(ub-lb>1){
			int md=(ub+lb)>>1;
			if(latermin[md]<=sum[i]){
				lb=md;
			}else ub=md;
		}
		if(maxi<lb-i){
			maxi=lb-i;
			num=1;
		}else if(maxi==lb-i){
			++num;
		}
	}
	if(maxi==0) puts("No solution");
	else printf("%d %d\n",maxi,num);
	return 0;
}
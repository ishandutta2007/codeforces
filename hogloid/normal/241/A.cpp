#include<iostream>
#include<algorithm>
#include<queue>
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
int m,k;
int d[1005],s[1005];
int main(){
	cin>>m>>k;
	REP(i,m) cin>>d[i];
	REP(i,m) cin>>s[i];
	
	int cur=0;
	int evermax=-1,res=0;
	REP(i,m){
		cur+=s[i];
		evermax=max(evermax,s[i]);
		cur-=d[i];
		res+=d[i];
		while(cur<0) cur+=evermax,res+=k;
	}
	cout<<res<<endl;
	return 0;
}
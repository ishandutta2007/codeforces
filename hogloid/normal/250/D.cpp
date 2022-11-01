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
int n,m;
double a,b,dst,dst2;
double A[100005],len[100005];
pair<double,double> B[100005];
double gcost(int i,int j){
	return sqrt(dst2+(B[j].fr-A[i])*(B[j].fr-A[i]))+len[i];
}
int main(){
	cin>>n>>m>>a>>b;
	dst=b-a;
	dst2=dst*dst;
	REP(i,n) cin>>A[i];
	REP(i,n) len[i]=sqrt(a*a+A[i]*A[i]);
	REP(i,m) cin>>B[i].fr;
	REP(i,m) cin>>B[i].sc;
	
	sort(A,A+n);
	double res=1e10;
	pi ans;
	REP(i,m){
		double tmp=B[i].sc;
		int lb=-1,ub=n;
		while(ub-lb>2){
			int l=(ub-lb)/3+lb,r=ub-(ub-lb)/3;
			if(gcost(l,i)<gcost(r,i)) ub=r;
			else lb=l;
		}
		tmp+=gcost(lb+1,i);
		if(res>tmp){
			res=tmp;
			ans=mp(lb+1,i);
		}
	}
	printf("%d %d\n",ans.fr+1,ans.sc+1);
	return 0;
}
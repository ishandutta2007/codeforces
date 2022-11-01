#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#define REP(i,m) for(int i=0;i<(int)m;++i)
#define REPN(i,m,in) for(int i=in;i<(int)m;++i)
#define pb push_back
#define mp make_pair
#define fr first
#define ALL(t) (t).begin(),(t).end()
#define sc second
#define INF ((int)5e8)
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define prl cerr<<"called:"<< __LINE__<<endl;
using namespace std;
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef long double ld;
typedef pair<int,int> pi;
int n,l,v1,v2;
pair<double,int> pos[600005];
double res[100005];
int main(){
	scanf("%d%d%d%d",&n,&l,&v1,&v2);
	double runtime=l/(double)(v1+v2);
	double runlen=runtime*v2;
	REP(i,n){
		int a;scanf("%d",&a);
		pos[i*6]=mp(a,-1);
		pos[i*6+1]=mp(a-runlen,1);
		pos[i*6+2]=mp(a+(double)l*2,-1);
		pos[i*6+3]=mp(a-runlen+l*2,1);
		pos[i*6+4]=mp(a-(double)l*2,-1);
		pos[i*6+5]=mp(a-(double)l*2-runlen,1);
	}
	sort(pos,pos+n*6);
	int sum=0;
	REP(i,n*6-1){
		sum+=pos[i].sc;
		res[sum]+=min(2.0*l,max(0.0,pos[i+1].fr))-min(2.0*l,max(0.0,pos[i].fr));
	}
	REP(i,n+1) res[i]/=2.0*l;
	REP(i,n+1) printf("%.11f\n",res[i]);
	return 0;
}
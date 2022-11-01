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
int n,m;
const double EPS=1e-15;
double p[3005][305];
double begin[305][3005],one[305],tmp[3005];
int main(){
	scanf("%d%d",&n,&m);
	REP(i,n) REP(j,m){
		int t;scanf("%d",&t);
		p[i][j]=t/1000.0;
	}

	REP(i,m){
		begin[i][0]=1;
		double cur=1.0;
		REP(j,n) one[i]+=cur*p[j][i],cur*=(1-p[j][i]);
	}
	double res=0;
	REP(hoge,n){
		int maxi=0;
		REP(i,m) if(one[i]>one[maxi]) maxi=i;
		
		int i=maxi;
		memcpy(tmp,begin[maxi],sizeof(tmp));
		res+=one[i];
		double cur=tmp[0];
		one[i]=begin[i][0]=0;
		REP(j,n) begin[i][j+1]=cur*p[j][i],cur*=(1-p[j][i]),cur+=tmp[j+1];
		cur=begin[i][0];
		REP(j,n) one[i]+=cur*p[j][i],cur*=(1-p[j][i]),cur+=begin[i][j+1];
	}
	printf("%.10f\n",res);
	return 0;
}
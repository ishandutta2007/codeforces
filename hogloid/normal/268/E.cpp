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
pi music[50005];
int n;
bool cmp(const pi& a,const pi& b){
	int costA=(100-b.sc)*a.sc*a.fr,costB=(100-a.sc)*b.sc*b.fr;
	return costA>costB;
}

int main(){
	cin>>n;
	REP(i,n) cin>>music[i].fr>>music[i].sc;

	sort(music,music+n,cmp);
	
	double res=0,sum=0;
	REP(i,n){
		res+=(100-music[i].sc)/100.0*sum;
		res+=music[i].fr;
		sum+=music[i].sc/100.0*music[i].fr;
	}
	printf("%.10f\n",res);


	return 0;
}
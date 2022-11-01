#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
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
int divv[105][105];
int factor[105];
int main(){
	int a,b,c;cin>>a>>b>>c;
	REPN(i,105,1){

		int tmp=i;
		for(int j=2;j*j<=tmp;++j){
			while(tmp%j==0){
				divv[i][j]++;
				tmp/=j;
			}
		}
		if(tmp>=2) divv[i][tmp]++;
	}
	int res=0,mod=(1<<30);
	REPN(i,a+1,1) REPN(j,b+1,1){
		memset(factor,0,sizeof(factor));
		REP(i2,105) factor[i2]+=divv[i][i2]+divv[j][i2];
		REPN(k,c+1,1){
			int tmp=1;
			REP(i2,105) factor[i2]+=divv[k][i2];
			REP(i2,105) tmp*=factor[i2]+1;
			res+=tmp;
			if(res>=mod) res-=mod;
			REP(i2,105) factor[i2]-=divv[k][i2];
		}
	}
	cout<<res<<endl;
		

	return 0;
}
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
int buf[2005][2005];

int csum[2005];
int main(){
	char tmp[2005];
	int n;scanf("%d",&n);
	REP(i,n){
		scanf("%s",tmp);
		REP(j,n) buf[i][j]=tmp[j]-'0';
	}
	int res=0;
	for(int i=n-1;i>=0;--i){
		int rsum=0;
		REP(j,i) if(buf[i][j]^rsum^csum[j]){
			rsum^=1;
			csum[j]^=1;
			++res;
		}
		buf[i][i]^=rsum;
	}

	REP(i,n) buf[i][i]^=csum[i];
	memset(csum,0,sizeof(csum));

	REP(i,n){
		int rsum=0;
		for(int j=n-1;j>i;--j) if(buf[i][j]^rsum^csum[j]){
			rsum^=1;
			csum[j]^=1;
			++res;
		}
		buf[i][i]^=rsum;
	}
	REP(i,n) buf[i][i]^=csum[i];

	REP(i,n) if(buf[i][i]) ++res;

	cout<<res<<endl;

	return 0;
}
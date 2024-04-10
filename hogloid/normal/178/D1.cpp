#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<numeric>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
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
int n;
int num[20];
int buf[5][5];
int main(){
	scanf("%d",&n);
	REP(i,n*n) scanf("%d",&num[i]);
	sort(num,num+n*n);
	int sum=accumulate(num,num+n*n,0)/n;
	do{
		REP(i,n) REP(j,n) buf[i][j]=num[i*n+j];
		int failed=0;
		REP(i,n){
			int tmp=0;
			REP(j,n) tmp+=buf[i][j];
			if(tmp!=sum) failed=1;
		}
		REP(i,n){
			int tmp=0;
			REP(j,n) tmp+=buf[j][i];
			if(tmp!=sum) failed=1;
		}
		int tmp=0;
		REP(i,n) tmp+=buf[i][i];
		if(tmp!=sum) failed=1;

		tmp=0;
		REP(i,n) tmp+=buf[i][n-1-i];
		if(tmp!=sum) failed=1;

		if(!failed){
			printf("%d\n",sum);
			REP(i,n) REP(j,n) printf("%d%c",buf[i][j],j==n-1?'\n':' ');
			return 0;
		}
	}while(next_permutation(num,num+n*n));


	return 0;
}
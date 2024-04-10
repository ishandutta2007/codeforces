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
int n,x;
int buf[35][35];
int back[35][35];
int solve(int bit){
	
	REP(i,n) REP(j,n) buf[i][j]=back[i][j];
	
	REP(i,x) if(bit>>i&1) REP(j,x) REP(k,x) buf[x-1+j][k+i]*=-1;

	REPN(i,n,x) REP(j,n) buf[i-x][j]+=buf[i][j];
	
	int tot=0;
	REP(i,x-1){
		int tmp1=0,//flip the rightmost
			tmp2=0; //not
		REP(j,x-1) tmp1+=abs(buf[i][j]-buf[i][j+x]);
		tmp1+=-buf[i][x-1];

		REP(j,x-1) tmp2+=abs(buf[i][j]+buf[i][j+x]);
		tmp2+=buf[i][x-1];


		tot+=max(tmp1,tmp2);
	}
	REP(i,n) {
		tot+=buf[x-1][i];
	}

	return tot;
}

int main(){
	cin>>n;
	x=(n+1)/2;
	REP(i,n) REP(j,n) cin>>back[i][j];

	
	int res=-INF;
	REP(i,1<<x){
		int tmp=solve(i);
		res=max(res,tmp);
	}
	printf("%d\n",res);
	return 0;
}
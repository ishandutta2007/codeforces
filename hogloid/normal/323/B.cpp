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
int n;
int buf[1005][1005];

int six_mat[]={
	0,1,1,1,0,0,
	0,0,1,0,1,0,
	0,0,0,1,1,1,
	0,1,0,0,1,1,
	1,0,0,0,0,1,
	1,1,0,0,0,0};

int main(){
	cin>>n;
	
	int m=3;
	if(n%2==0){
		if(n<6){
			puts("-1");
			return 0;
		}
		int cnt=0;
		REP(i,6) REP(j,6) buf[i][j]=six_mat[cnt++];
		m=6;
	}else{
		buf[0][1]=1;buf[1][2]=1;
		buf[2][0]=1;
	}

	while(m<n){
		buf[m][m+1]=1;
		REP(i,m) buf[i][m]=1,buf[m+1][i]=1;
		m+=2;
	}
	REP(i,n) REP(j,n) printf("%d\n",buf[i][j]);



	return 0;
}
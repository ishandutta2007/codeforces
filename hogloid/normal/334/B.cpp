#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
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

int x[10],y[10];
pi p[10];
int judge(){
	REP(i,8){
		cin>>x[i]>>y[i];
		p[i]=mp(x[i],y[i]);
	}
	sort(x,x+8);
	sort(y,y+8);
	int xn=unique(x,x+8)-x;
	int yn=unique(y,y+8)-y;

	if(xn!=3 || yn!=3) return false;

	REP(i,3) REP(j,3) if(!(i==1 && j==1)){
		pi q=mp(x[i],y[j]);
		int ok=0;
		REP(k,8) if(p[k]==q) ok=1;
		if(!ok) return false;
	}
	return true;
}

int main(){
	if(judge()) puts("respectable");
	else puts("ugly");

	return 0;
}
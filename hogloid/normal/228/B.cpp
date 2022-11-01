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
int h[2],w[2];
char buf[2][55][55];
int main(){
	REP(i,2){
		cin>>h[i]>>w[i];
		REP(j,h[i]){
			scanf("%s",buf[i][j]);
		}
	}
	int maxi=-1,rx,ry;
	REPN(i,55,-55) REPN(j,55,-55){
		int tmp=0;
		REP(i2,h[0]) if(i+i2>=0 && i+i2<h[1]) REP(j2,w[0]) if(buf[0][i2][j2]=='1' &&
				j+j2>=0 && j+j2<w[1] && buf[1][i+i2][j+j2]=='1'){
			++tmp;
		}
		if(tmp>maxi){
			maxi=tmp;
			rx=j;ry=i;
		}
	}
	cout<<ry<<' '<<rx<<endl;
			
	return 0;
}
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

char buf[505][505];
int frac[505][505][10];
int sum[505][505];
int h,w;
int dx[]={0,1,0,1},dy[]={0,0,1,1};
int main(){
	scanf("%d%d",&h,&w);
	REP(i,h) scanf("%s",buf[i]);
	int res=0;
	for(int size=2,k=0;size<=w && size<=h;size*=2,++k) REP(i,h-size+1) REP(j,w-size+1){
		if(k==0){
			REP(i2,4) if(buf[i+dy[i2]][j+dx[i2]]=='*') frac[i][j][k]|=(1<<i2);
		}else{
			frac[i][j][k]=-1;
			REP(pat,16){
				int flag=1;
				REP(i2,4){
					int px=j+dx[i2]*size/2,py=i+dy[i2]*size/2;
					if(pat>>i2&1){
						flag&= (frac[py][px][k-1]==15);
					}else{
						flag&= (frac[py][px][k-1]==pat);
					}
				}
				if(flag) frac[i][j][k]=pat,++res;
			}
		}
	}
	printf("%d\n",res);

	return 0;
}
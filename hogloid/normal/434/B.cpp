#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;

int h,w,q;
int buf[4][1005][1005];
int xsum[4][1005][1005];

int state;
void flip(int k,int y,int x){
	int add;
	if(buf[k][y][x]) add=-1;
	else add=1;
	buf[k][y][x]^=1;
	
	
	if(state) {
		REPN(i,w,x) xsum[k][y][i+1]+=add;
	}else xsum[k][y][x+1]+=add;

}
void rotate(int& y,int& x){
	int nx=w-y-1,ny=x;

	x=nx;y=ny;
}
int check(int k,int y,int x){

	if(buf[k][y][x]==0) return 0;

	int l=0,r=w;
	
	int area=0;
	for(int i=y;i>=0;--i){
		while(r-x>0 && xsum[k][i][r]-xsum[k][i][x]<r-x) --r;
		while(l<=x && xsum[k][i][x+1]-xsum[k][i][l]<x-l+1) ++l;

		if(r-x==0 || l>x) break;
		chmax(area,(r-l)*(y-i+1));
	}

	return area;
}

int main(){
	cin>>h>>w>>q;

	int ph=h,pw=w;
	h=max(h,w);
	w=max(h,w);
	REP(i,ph) REP(j,pw){
		int x=j,y=i;
		int a;scanf("%d",&a);
		if(a){
			REP(k,4){
				flip(k,y,x);
				rotate(y,x);
			}
		}
	}
	REP(k,4) REP(i,h) REP(j,w) xsum[k][i][j+1]+=xsum[k][i][j];
	
	state=1;

	REP(hoge,q){
		int op,x,y;scanf("%d%d%d",&op,&x,&y);
		--x;--y;
		if(op==1){
			REP(k,4){
				flip(k,x,y);
				rotate(x,y);
			}
		}else{
			int res=0;
			REP(k,4){
				int tmp=check(k,x,y);
				chmax(res,tmp);
				rotate(x,y);
			}
			printf("%d\n",res);
		}
	}


	return 0;
}
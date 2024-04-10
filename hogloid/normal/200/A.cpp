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
int h,w,k;
pi query[100005];
int L[2005][2005],R[2005][2005];
int putted[2005][2005];
int y,x;
void renew(int y,int x,int& ay,int& ax,int y2,int x2){
	int d1=abs(ay-y)+abs(ax-x),d2=abs(y-y2)+abs(x-x2);
	if(d1>d2 || (d1==d2 && mp(ay,ax)>mp(y2,x2))){
		ay=y2;
		ax=x2;
	}
}

pi findpos(int y,int x){
	int ay=INF,ax=INF;
	for(int d=0;d<=2002;++d){
		if(abs(y-ay)+abs(x-ax)<d) break; 
		int y2=y-d,x2;
		if(y2>=0){
			x2=L[y2][x];
			if(x2>=0) renew(y,x,ay,ax,y2,x2);

			x2=R[y2][x];
			if(x2<w) renew(y,x,ay,ax,y2,x2);
		}

		y2=y+d;
		if(y2<h){
			x2=L[y2][x];
			if(x2>=0) renew(y,x,ay,ax,y2,x2);

			x2=R[y2][x];
			if(x2<w) renew(y,x,ay,ax,y2,x2);
		}
	}
	return mp(ay,ax);
}
void fill(int y,int x){
	putted[y][x]=1;
	L[y][x]=(x==0?-1:L[y][x-1]);
	for(int i=x+1;i<w;++i){
		if(!putted[y][i]) continue;
		L[y][i]=L[y][i-1];
	}

	R[y][x]=(x==w-1?INF:R[y][x+1]);
	for(int i=x-1;i>=0;--i){
		if(!putted[y][i]) continue;
		R[y][i]=R[y][i+1];
	}
}

int main(){
	cin>>h>>w>>k;
	REP(i,k){
		cin>>query[i].fr>>query[i].sc;
		--query[i].fr;
		--query[i].sc;
	}
	REP(i,h) REP(j,w) L[i][j]=R[i][j]=j;

	REP(i,k){
		pi p=findpos(query[i].fr,query[i].sc);
		printf("%d %d\n",p.fr+1,p.sc+1);
		fill(p.fr,p.sc);
	}

	return 0;
}
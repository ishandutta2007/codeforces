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

int h,w;
int buf[3005][3005];
int sum[3005][3005];

int getarea(int sy,int sx,int gy,int gx){
	int tmp= sum[gy][gx]+sum[sy+1][sx+1]-sum[gy][sx+1]-sum[sy+1][gx];
	return tmp;
}

int isPath(int sy,int sx,int gy,int gx){
	int tmp= sum[gy+1][gx+1]+sum[sy][sx]-sum[gy+1][sx]-sum[sy][gx+1]
		-buf[sy][sx]-buf[gy][gx];
	if(tmp==0) return 0;
	if(tmp==abs(sx-gx)+abs(gy-sy)-1) return 1;
	return -1;
}

char deg[3005][3005];

struct uf{
	int par[9000005];
	void init(int n){
		REP(i,n+1) par[i]=-1;
	}
	int root(int a){
		if(par[a]==-1) return a;
		return par[a]=root(par[a]);
	}
	void unite(int a,int b){
		a=root(a);b=root(b);
		if(a==b) return;
		par[a]=b;
	}
};
uf u;
int SIZE=1001;
int main(){
	cin>>h>>w;
	REP(i,h) REP(j,w) scanf("%d",&buf[i+SIZE][j+SIZE]);
	h+=SIZE*2;
	w+=SIZE*2;
	
	REP(i,h) REP(j,w) sum[i+1][j+1]=sum[i][j+1]+sum[i+1][j]-sum[i][j]+buf[i][j];
	int sx,sy=-1;
	REP(i,h) REP(j,w) if(sy==-1 && buf[i][j]){
		sx=j;sy=i;
	}

	if(sum[h][w]==1){
		puts("-1");
		return 0;
	}
	
	
	int ans=0;
	for(int k=2;k<=SIZE-1;++k){
		int sx2=sx%k,sy2=sy%k;
		
		int fail=0;

		int h2=h/k,w2=w/k;
		
		u.init(h2*w2);
		REP(i,h2+1) REP(j,w2+1) deg[i][j]=0;
		for(int i=sy2;i<h;i+=k) for(int j=sx2;j<w;j+=k){
			int y=i/k,x=j/k;
			if(i+k<h){
				int t=isPath(i,j,i+k,j);
				if(t==-1) fail=1;
				if(t==1){
					++deg[y][x],++deg[y+1][x];
					u.unite(y*w2+x,(y+1)*w2+x);
				}
			}
			if(j+k<w){
				int t=isPath(i,j,i,j+k);
				if(t==-1) fail=1;
				if(t==1) {
					++deg[y][x],++deg[y][x+1];
					u.unite(y*w2+x,y*w2+x+1);
				}
			}
			if(i+k<h && j+k<w){
				if(getarea(i,j,i+k,j+k)) fail=1;
			}
		}
		if(fail) continue;
		
		int odd=0,r=-1;
		REP(i,h2) REP(j,w2){
			int py=sy2+i*k,px=sx2+j*k;
			if(buf[py][px]){
				if(deg[i][j]&1) ++odd;
				if(r==-1 || r==u.root(w2*i+j)) r=u.root(w2*i+j);
				else fail=1;
			}
			if(buf[py][px]==0 && deg[i][j]){
				fail=1;
			}
		}
		if(odd>2) fail=1;
		if(!fail) printf("%d\n",k),ans=1;
	}
	if(!ans) puts("-1");



	return 0;
}
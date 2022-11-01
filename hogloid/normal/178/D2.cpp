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
static const int INF =1000000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
int n;
int num[20];
int buf[5][5],ans[5][5];
pi kind[20];
int sum;
int m;
int check(){
	int tmp;
	REP(i,n){
		tmp=0;
		REP(j,n){
			if(buf[i][j]==-INF) goto ex1;
			tmp+=buf[i][j];
		}
		if(tmp!=sum) return 1;
	}
	ex1:;
	REP(i,n){
		tmp=0;
		REP(j,n){
			if(buf[j][i]==-INF) goto ex2;
			tmp+=buf[j][i];
		}
		if(tmp!=sum) return 1;
	}
	ex2:;
	tmp=0;
	REP(i,n){
		if(buf[i][i]==-INF) goto ex3;
		tmp+=buf[i][i];
	}
	if(tmp!=sum) return 1;
	ex3:;
	tmp=0;
	REP(i,n){
		if(buf[i][n-1-i]==-INF) goto ex4;
		tmp+=buf[i][n-1-i];
	}
	if(tmp!=sum) return 1;
	ex4:;
	return 0;
}
int dfs(int x,int y){
	if(x==n){
		x=0;++y;
	}
	if(check()) return 0;
	if(y==n){
		memcpy(ans,buf,sizeof(ans));
		return 1;
	}
	REP(i,m) if(kind[i].sc>0){
		buf[y][x]=kind[i].fr;
		--kind[i].sc;
		if(dfs(x+1,y)) return 1;
		buf[y][x]=-INF;
		++kind[i].sc;
	}
	return 0;
}

int main(){
	scanf("%d",&n);
	REP(i,n) REP(j,n) buf[i][j]=-INF;
	REP(i,n*n) scanf("%d",&num[i]);
	sort(num,num+n*n);
	sum=accumulate(num,num+n*n,0)/n;
	m=0;
	REP(i,n*n){
		int j=i;
		while(j<n*n && num[j]==num[i]) ++j;
		kind[m++]=mp(num[i],j-i);
		i=j-1;
	}
	dfs(0,0);
	printf("%d\n",sum);
	REP(i,n) REP(j,n) printf("%d%c",ans[i][j],j==n-1?'\n':' ');


	return 0;
}
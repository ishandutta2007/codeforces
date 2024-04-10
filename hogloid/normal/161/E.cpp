#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#define REP(i,m) for(int i=0;i<(int)m;++i)
#define REPN(i,m,in) for(int i=in;i<(int)m;++i)
#define pb push_back
#define mp make_pair
#define fr first
#define ALL(t) (t).begin(),(t).end()
#define sc second
#define INF ((int)5e8)
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define prl cerr<<"called:"<< __LINE__<<endl;
using namespace std;
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef long double ld;
typedef pair<int,int> pi;
int prime[100005];
int memo[100005][7];
int ten[8];
int N;
int n_a[10];
int n;
int buf[10][10];
int rowsum[10];
int dfs(int y,int x){
	if(x>=n){
		x=0;
		++y;
	}
	if(y==n){
		int res=1;
		REPN(i,n,1){
			res*=memo[rowsum[i]][n-1-i];
		}
		return res;
	}
	int res=0;
	if(y==0){
		rowsum[0]+=n_a[n-1-x]*ten[n-1-x];
		buf[y][x]=n_a[n-1-x];
		res=dfs(y,x+1);
		rowsum[0]-=n_a[n-1-x]*ten[n-1-x];
		return res;
	}else if(y>x){
		rowsum[y]+=buf[x][y]*ten[n-1-x];
		res=dfs(y,x+1);
		rowsum[y]-=buf[x][y]*ten[n-1-x];
	}else if(y==x){
		return dfs(y,x+1);
	}else{//y<x
		REP(i,10){
			if(x==n-1 && (i==4 || i==6 || i==8)) continue;
			buf[y][x]=i;
			rowsum[y]+=i*ten[n-1-x];
			res+=dfs(y,x+1);
			rowsum[y]-=i*ten[n-1-x];
		}
	}
	return res;
}
int main(){
	REP(i,100005) prime[i]=1;
	prime[0]=prime[1]=0;
	for(int i=2;i*i<100000;++i) if(prime[i]){
		for(int j=i*i;j<100000;j+=i) prime[j]=0;
	}
	ten[0]=1;
	REP(i,7) ten[i+1]=ten[i]*10;
	REP(i,100000) if(prime[i]){
		int tmp[7]={0};
		int n=i;
		REP(j,5) tmp[j]=n%10,n/=10;
		REP(j,5) memo[i-ten[j]*tmp[j]][j]++;
	}

	int t;scanf("%d",&t);
	while(t--){
		scanf("%d",&N);
		if(prime[N]==0){
			printf("%d\n",0);
			continue;
		}
		int tmp=N;
		n=0;
		while(tmp>0){
			n_a[n++]=tmp%10;
			tmp/=10;
		}
		memset(rowsum,0,sizeof(rowsum));
		memset(buf,0,sizeof(buf));
		printf("%d\n",dfs(0,0));
	}


	return 0;
}
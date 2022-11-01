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
int n,m,k;
int buf[1005][1005];

int col[20][20];

int reach[20][20];
const lint mod=1000000007;
int match[20],appear[20],rev[20];
lint calc(){

	memset(rev,-1,sizeof(rev));
	memset(match,-1,sizeof(match));
	memset(appear,0,sizeof(appear));
	REP(i,n) REP(j,m) appear[col[i][j]]=1;
	REP(i,n) REP(j,m) if(~buf[i][j]){
		if(match[buf[i][j]]!=-1 && match[buf[i][j]]!=col[i][j]) return 0;
		match[buf[i][j]]=col[i][j];
		if(rev[col[i][j]]!=-1 && rev[col[i][j]]!=buf[i][j]) return 0;
		rev[col[i][j]]=buf[i][j];
	}

	int k2=0;
	REP(i,k) if(appear[i]) ++k2;
	
	int emp=0,cont=0;
	REP(i,k){
		if(appear[i] && rev[i]==-1) ++emp;
		if(rev[i]!=-1) ++cont;
	}
	
	lint ans=1;
	REP(i,emp) ans*=(k-cont-i);

	ans%=mod;
	return ans;
}

lint dfs(int y,int x,int used){
	if(x==m){
		x=0;
		++y;
	}
	if(y==n) return calc();
	
	lint res=0;
	reach[y][x]=((y>0?reach[y-1][x]:0)|(x>0?reach[y][x-1]:0));
	REP(i,min(used+1,k)){
		if(reach[y][x]>>i&1) continue;
		reach[y][x]|=(1<<i);
		col[y][x]=i;
		res+=dfs(y,x+1,max(used,i+1));
		if(res>=mod) res-=mod;
		
		reach[y][x]^=(1<<i);
	}
	return res;
}

lint solve(){
	if(n+m-1>k) return 0;
	
	return dfs(0,0,0);
}
	
int main(){

	cin>>n>>m>>k;
	REP(i,n) REP(j,m){
		scanf("%d",&buf[i][j]);
		--buf[i][j];
	}

	cout<<solve()<<endl;

	return 0;
}
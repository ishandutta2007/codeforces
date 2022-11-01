#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
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
int n,u,r;
int a[50],b[50],k[50],p[50];
lint calc(int ns[]){
	lint res=0;
	REP(i,n) res+=ns[i]*(lint)k[i];
	return res;
}
void move(int ns[]){
	int temp[31];
	REP(i,n) temp[i]=ns[p[i]]+r;
	REP(i,n) ns[i]=temp[i];
}
void flip(int ns[]){
	REP(i,n) ns[i]^=b[i];
}
lint inf2=(lint)(1e18);
lint dfs2(int dep,int ns[]){
	if(u<dep || (u-dep)%2) return -inf2;
	return calc(ns);
}
lint dfs(int dep,int ns[]){
	if(u<dep) return -inf2;
	lint mid=-inf2;
	if((u-dep)%2==0) mid=calc(ns);
	lint left,right;
	int nxt[31];
	REP(i,n) nxt[i]=ns[i];
	move(nxt);
	left=dfs(dep+1,nxt);
	REP(i,n) nxt[i]=ns[i];
	flip(nxt);
	mid=max(mid,dfs2(dep+1,nxt));
	move(nxt);
	right=dfs(dep+2,nxt);
	return max(mid,max(left,right));
}

int main(){
	scanf("%d%d%d",&n,&u,&r);
	REP(i,n) scanf("%d",&a[i]);
	REP(i,n) scanf("%d",&b[i]);
	REP(i,n) scanf("%d",&k[i]);
	REP(i,n) scanf("%d",&p[i]),--p[i];
	
	
	cout<<dfs(0,a)<<endl;
	return 0;
}
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
int n;
char buf[5005][5005];
vector<int> loop,ever;
int vis[5005];
bool dfs(int v){
	vis[v]=1;
	ever.pb(v);
	REP(i,n) if(buf[v][i]=='1'){
		if(vis[i]==1){
			ever.pb(i);
			do{
				loop.pb(ever.back());
				ever.pop_back();
			}while(ever.back()!=i);
			reverse(ALL(loop));
			return true;
		}
		if(vis[i]==2) continue;
		if(dfs(i)) return true;
	}
	vis[v]=2;
	ever.pop_back();
	return false;
}
void solve(int l,int r){
	REPN(i,r-1,l+1){
		int a=loop[l],b=loop[i],c=loop[r-1];
		if(buf[a][b]=='1' && buf[b][c]=='1'){
			printf("%d %d %d\n",a+1,b+1,c+1);
			return;
		}else if(buf[a][b]=='0'){
			solve(l,i+1);
			return;
		}else{
			solve(i,r);
			return;
		}
	}
}


int main(){
	cin>>n;
	REP(i,n) scanf("%s",buf[i]);

	REP(i,n) if(!vis[i]){
		if(dfs(i)){
			solve(0,loop.size());
			return 0;
		}
	}
	puts("-1");



	return 0;
}
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
char s[2005][505];
int n,K;
int len[2005];
int lcp[25][25];
int main(){
	
	scanf("%d%d",&n,&K);
	REP(i,n) scanf("%s",s[i]);
	REP(i,n) len[i]=strlen(s[i]);
	REP(i,n) REP(j,n){
		for(lcp[i][j]=0;lcp[i][j]<len[i] && lcp[i][j]<len[j] 
			&& s[i][lcp[i][j]]==s[j][lcp[i][j]];++lcp[i][j]);
	}
	int res=0;
	REP(i,(1<<n)) if(__builtin_popcount(i)==K){
		int cur=0;
		REP(j,n) if(i>>j&1) REP(k,j) if(i>>k&1){
			cur+=lcp[j][k];
		}
		res=max(res,cur);
	}
	printf("%d\n",res);
	return 0;
}
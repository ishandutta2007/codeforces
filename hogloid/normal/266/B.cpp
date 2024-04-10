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
int n,t;
char s[55],nxt[55];
int main(){
	scanf("%d%d",&n,&t);
	scanf("%s",s);

	REP(hoge,t){
		memcpy(nxt,s,sizeof(s));
		REP(j,n-1) if(s[j]=='B' && s[j+1]=='G') swap(nxt[j],nxt[j+1]);
		memcpy(s,nxt,sizeof(s));
	}
	printf("%s\n",s);
	return 0;
}
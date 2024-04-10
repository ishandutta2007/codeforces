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
char s[6005],t[2005];
int main(){
	REP(i,2000) s[i]='$';
	scanf("%s",s+2000);
	int len=strlen(s);
	REPN(i,6002,len) s[i]='$';

	scanf("%s",t);
	int len2=strlen(t);
	int ans=INF;
	REP(i,len){
		int dif=0;
		REP(j,len2) if(s[i+j]!=t[j]) ++dif;
		ans=min(ans,dif);
	}
	cout<<ans<<endl;
	return 0;
}
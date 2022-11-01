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
char s[200005],t[200005];
int cover[200005],cover2[200005];
int sum[27][200005];
int main(){
	scanf("%s%s",s,t);
	int lens=strlen(s),lent=strlen(t);
	REP(i,lens){
		cover[i+1]=cover[i];
		if(cover[i]<lent && t[cover[i]]==s[i]) ++cover[i+1];
	}
	cover2[lens]=lent-1;
	for(int i=lens-1;i>=0;--i){
		cover2[i]=cover2[i+1];
		if(cover2[i]>=0 && t[cover2[i]]==s[i]) --cover2[i];
	}
	int able=0;
	REP(j,26) REP(i,lent) sum[j][i+1]=sum[j][i]+((t[i]-'a'==j)?1:0);
	REP(i,lens){
		int begin=cover[i],end=cover2[i+1];//[begin,end]
		if(sum[s[i]-'a'][min(lent,begin+1)]-sum[s[i]-'a'][max(0,end)]>=1) ++able;
	}
	if(able==lens) puts("Yes");
	else puts("No");
	return 0;
}
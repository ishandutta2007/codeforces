#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
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

char t[10];
char s[205];

int cnt[15],use[15];
int main(){
	scanf("%s%s",t,s);
	int len=strlen(s);
	REP(i,len) cnt[s[i]-'0']++;
	cnt[6]+=cnt[9];
	cnt[2]+=cnt[5];
	
	int len2=strlen(t);
	REP(i,len2) use[t[i]-'0']++;
	use[6]+=use[9];
	use[2]+=use[5];
	
	int mini=INF;
	REP(i,10) if(i!=9 && i!=5 && use[i]){
		mini=min(mini,cnt[i]/use[i]);
	}
	printf("%d\n",mini);



	return 0;
}
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
char s[100005];

int appear[15];
int main(){
	scanf("%s",s);
	n=strlen(s);
	
	int q=0;
	REP(i,n) if(s[i]>='A' && s[i]<='J'){
		appear[s[i]-'A']=1;
	}
	REP(i,n) if(s[i]=='?') ++q;
	int cnt=0;
	REP(i,10) if(appear[i]) ++cnt;

	int res=1;
	if(s[0]>='A' && s[0]<='J'){
		REP(i,cnt) res*=10-i;
		res/=10;
		res*=9;
	}else{
		REP(i,cnt) res*=10-i;
	}

	if(s[0]=='?'){
		res*=9;
		--q;
	}

	printf("%d",res);
	REP(i,q) putchar('0');
	puts("");


	return 0;
}
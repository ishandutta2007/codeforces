#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
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
int n,len;
char s[1000005];
int var[1000005][4];
int cnt,ind;
int parse(){
	if(s[ind]=='0') var[cnt][0]=1;
	if(s[ind]=='1') var[cnt][3]=1;
	if(s[ind]=='?') var[cnt][1]=var[cnt][2]=1;
	++cnt;
	int v=cnt-1;
	if(s[ind]=='('){
		++ind;
		int p=parse(),p2;
		char ope=s[ind];
		++ind;
		p2=parse();
		REP(i,4) if(var[p][i]) REP(j,4) if(var[p2][j]){
			int x1=i&1,x2=i>>1&1,y1=j&1,y2=j>>1&1;
			int bit;
			if(ope=='&') bit=(x1&y1)+(x2&y2)*2;
			if(ope=='|') bit=(x1|y1)+(x2|y2)*2;
			if(ope=='^') bit=(x1^y1)+(x2^y2)*2;
			var[v][bit]=1;
		}
	}
	++ind;
	return v;
}


int main(){
	scanf("%d%s",&n,s);
	len=strlen(s);
	int root=parse();
	if(var[0][2] || var[0][1]) puts("YES");
	else puts("NO");
	return 0;
}
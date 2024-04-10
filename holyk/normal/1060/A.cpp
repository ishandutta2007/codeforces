#include<bits/stdc++.h>
#define REP(i,a,b) for(int i(a);i<=(b);++i)
using namespace std;
typedef long long ll;
inline int read(){char c,p=0;int w;
	while(!isdigit(c=getchar()))if(c=='-')p=1;w=c^'0';
	while(isdigit(c=getchar()))w=w*10+(c^'0');return p?-w:w;
}
inline bool smin(int&x,const int&y){return x>y?x=y,1:0;}
inline bool smax(int&x,const int&y){return x<y?x=y,1:0;}
int n,c[10];
char s[102];
int main(){
	scanf("%d%s",&n,s+1);
	REP(i,1,n)++c[s[i]-'0'];
//	if(!c[8])return puts("0"),0;
	cout<<min(n/11,c[8]);
	return 0;
}
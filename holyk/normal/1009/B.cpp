#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define DEC(i,a,b) for(int i=(a);i>=(b);--i)
#define dbg(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
template<typename T,typename U> inline bool smax(T&x,const U&y){return y>x?(x=y,1):0;}
template<typename T,typename U> inline bool smin(T&x,const U&y){return y<x?(x=y,1):0;}
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define X first
#define Y second
inline int read(){
    int w=0,p=0;char c;
    while(!isdigit(c=getchar()))if(c=='-')p=1;
    while(isdigit(c))w=(w<<1)+(w<<3)+(c^'0'),c=getchar();
    return p?-w:w;
}
char s[100005];
int n;
int main(){
	cin>>s+1;
	n=strlen(s+1);
	int cnt=0,f=0;
	REP(i,1,n)if(s[i]=='1')++cnt;
	REP(i,1,n){
		if(s[i]=='2'&&!f){f=1;REP(j,1,cnt)putchar('1');}
		if(s[i]!='1')putchar(s[i]);
	}
	if(!f)while(cnt--)putchar('1');
	return 0;
}
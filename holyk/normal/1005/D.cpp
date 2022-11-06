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
const int N=2e5+5;
char s[N];
int n,a[N],f[N],mxf[3];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	REP(i,1,n)a[i]=(a[i-1]+s[i]-'0')%3;
	mxf[1]=mxf[2]=-1;
	int ans=0;
	REP(i,1,n){
		if(s[i]=='0')f[i]=f[i-1]+1;
		smax(f[i],mxf[a[i]]+1);
		REP(j,0,2)smax(f[i],mxf[j]);
		smax(ans,f[i]);
		if(s[i+1]!='0')smax(mxf[a[i]],f[i]);
	}
	cout<<ans;
	return 0;
}
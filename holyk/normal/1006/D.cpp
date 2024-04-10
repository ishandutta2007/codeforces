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
const int N=1e5+5;
int n;
char a[N],b[N];
int calc(char a,char b,char c,char d){
	map<char,int>p;++p[a],++p[b],++p[c],++p[d];
	if(p.size()==1)return 0;
	if(p.size()==2)return p.begin()->Y==2?0:1;
	if(p.size()==3)return a==c?2:1;
	return 2;
}
int main(){
	scanf("%d%s%s",&n,a+1,b+1);
	int ans=0;
	REP(i,1,n>>1)ans+=calc(a[i],b[i],a[n-i+1],b[n-i+1]);
	if(n&1)ans+=a[n/2+1]!=b[n/2+1];
	cout<<ans;
	return 0;
}
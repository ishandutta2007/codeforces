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
unordered_set<int> s,p;
int n,a[120005];
int main(){
	n=read();
	REP(i,1,n){
		a[i]=read();
		REP(j,1,30)if(s.find((1<<j)-a[i])!=s.end())
		p.insert((1<<j)-a[i]),p.insert(a[i]);
		s.insert(a[i]);
	}
	int ans=0;
	REP(i,1,n)if(p.find(a[i])==p.end())++ans;
	cout<<ans;
	return 0;
}
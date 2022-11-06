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
int n;
ll s[200005],ans;
unordered_multiset<ll> p; 
int main(){
	n=read();
	REP(i,1,n)s[i]=read()+s[i-1];
	REP(i,1,n)p.insert(s[n]-s[n-i]);
	REP(i,1,n){
		auto k=p.find(s[n]-s[i-1]);
		if(k!=p.end())p.erase(k);
		if(p.find(s[i])!=p.end())smax(ans,s[i]);
	}
	cout<<ans;
	return 0;
}
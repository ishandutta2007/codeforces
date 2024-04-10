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

const int N=1007;
string s,y;
unordered_set<string> ss;
int vis[26];
int main(){
	int n=read();
	REP(i,1,n){
		cin>>s;
		memset(vis,0,sizeof vis);
		for(auto i:s)vis[i-'a']=1;
		s="";
		REP(i,0,25)if(vis[i])s+=i+'a';
		ss.insert(s);
	}
	cout<<ss.size();
	return 0;
}
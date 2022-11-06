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
int n,q,cnt[33];
int main(){
	n=read(),q=read();
	REP(i,1,n)cnt[(int)log2(read())]++;
	while(q--){
		int x=read(),ans=0;
		DEC(i,30,0){
			if(!x)break;
			if((1ll<<i)*cnt[i]<=x)ans+=cnt[i],x-=(1ll<<i)*cnt[i];
			else ans+=x/(1<<i),x-=x/(1<<i)*(1<<i);
		}
	//	dbg("err %d\n",x);
		printf("%d\n",x?-1:ans);
	}
	return 0;
}
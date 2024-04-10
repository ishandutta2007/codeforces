#include<bits/stdc++.h>
#define REP(i,a,b) for(int i(a);i<=(b);++i)
#define dbg(...) fprintf(stderr,__VA_ARGS__)

typedef long long ll;

template<typename T,typename U> inline bool smax(T&x,const U&y){return y>x?(x=y,1):0;}
template<typename T,typename U> inline bool smin(T&x,const U&y){return y<x?(x=y,1):0;}
const int N=2e5+5,P=998244353;
int n;
char s[N];
int la,lb;
int main(){
	scanf("%d%s",&n,s+1);
	if(n==1)return puts("1"),0;
	la=lb=1;
	REP(i,2,n)if(s[i]==s[i-1])++la;else break;
	REP(i,2,n)if(s[n-i+1]==s[n-i+2])++lb;else break;
	if(s[1]^s[n])return printf("%d\n",la+lb+1),0;
	if(la+lb==n)return std::cout<<1ll*n*(n+1)/2%P,0;
	std::cout<<1ll*(la+1)*(lb+1)%P;
	return 0;
}
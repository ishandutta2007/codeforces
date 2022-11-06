#include<bits/stdc++.h>
#define REP(i,a,b) for(int i(a);i<=(b);++i)
#define dbg(...) fprintf(stderr,__VA_ARGS__)

typedef long long ll;

#define gc getchar()
inline int read(){char c,p=0;int w;
	while(isspace(c=gc));if(c=='-')c=gc,p=1;w=c&15;
	while(isdigit(c=gc))w=w*10+(c&15);return p?-w:w;
}

template<typename T,typename U> inline bool smax(T&x,const U&y){return y>x?(x=y,1):0;}
template<typename T,typename U> inline bool smin(T&x,const U&y){return y<x?(x=y,1):0;}

int main(){
	int T=read();
	while(T--){
		int x=read();
		ll t=x/std::__gcd(x,180),u=t;
		while(180ll*u<=1ll*(u+1)*x)u+=t;
		printf("%I64d\n",180ll*u/x);
	}
	return 0;
}
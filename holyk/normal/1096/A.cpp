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
	int t=read();
	while(t--){
		int x=read(),y=read();
		printf("%d %d\n",x,x<<1);
	} 
	return 0;
}
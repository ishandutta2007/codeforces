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
const int N=1e5+5;
int n,m,t[N];
ll a[N],f[N][4];
char mp[666],s[N];
int main(){
	mp['h']=1,mp['a']=2,mp['r']=3,mp['d']=4;
	n=read();
	scanf("%s",s+1);
	REP(i,1,n)t[i]=read();
	REP(i,1,n)if(mp[s[i]]){
		s[i]=mp[s[i]];
		if(s[i]^s[m])s[++m]=s[i];
		a[m]+=t[i];			
	}
	REP(i,1,m){
		REP(j,0,3)f[i][j]=f[i-1][j];
		if(s[i]<4)smin(f[i][s[i]],f[i-1][s[i]-1]);
		f[i][s[i]-1]=f[i-1][s[i]-1]+a[i];		
	}
	std::cout<<std::min({f[m][0],f[m][1],f[m][2],f[m][3]});
	return 0;
}
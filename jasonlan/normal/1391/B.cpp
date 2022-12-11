#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
inline char readch(){
	char ch=getchar();
	while(ch<'A'||ch>'Z')ch=getchar();
	return ch;
}
int main(){
	int T=read();
	while(T--){
		n=read();m=read();
		int ans=0;
		for(register int i=1;i<=n;++i)
			for(register int j=1;j<=m;++j)
				if(i==n){
					if(j==m)readch();
					else ans+=readch()=='D';
				}
				else if(j==m)ans+=readch()=='R';
				else readch();
		printf("%d\n",ans);
	}
	return 0;
}
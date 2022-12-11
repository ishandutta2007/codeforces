#include<iostream>
#include<cstdio>
using namespace std;
int n,ans;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	for(register int T=read();T;--T){
		n=read();
		ans=0;
		for(register int i=1,flag=0,cnt=0;i<=n;++i)
			if(!read())++cnt;
			else{
				if(!flag)flag=1;
				else ans+=cnt;
				cnt=0;
			}
		printf("%d\n",ans);
	}
	return 0;
}
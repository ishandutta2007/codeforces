#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=201000;
int n,k,mini,maxi,a[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main()
{
	int T=read();
	while(T--){
		n=read();k=read();
		mini=1e9;maxi=-1e9;
		for(register int i=0;i<n;++i){
			a[i]=read();
			mini=min(mini,a[i]);
			maxi=max(maxi,a[i]);
		}
		if(k&1){
			for(register int i=0;i<n;putchar(++i==n?'\n':' '))
				printf("%d",maxi-a[i]);
		}
		else{
			for(register int i=0;i<n;putchar(++i==n?'\n':' '))
				printf("%d",(maxi-mini)-(maxi-a[i]));
		}
	}
	return 0;
}
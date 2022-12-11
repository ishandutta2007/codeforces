#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=301000;
int n,k;
char ch[maxn],ch2[maxn];
inline int read(){
	int res=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return res;
}
int main(){
	for(register int T=read(),cnt,cempty;T;--T){
		n=read();k=read();
		scanf("%s",ch);
		bool flag=true;
		cnt=cempty=0;
		for(register int i=0;i<k&&flag;++i){
			ch2[i]='?';
			for(register int j=i;j<n;j+=k)
				if(ch2[i]=='?'||ch2[i]==ch[j]||ch[j]=='?')
					ch2[i]=ch[j]=='?'?ch2[i]:ch[j];
				else{
					flag=false;
					break;
				}
			if(ch2[i]=='?')++cempty;
			else cnt+=ch2[i]=='0'?1:-1;
		}
		cnt=abs(cnt);
		if(cnt>cempty)flag=false;
		if(!flag)puts("NO");
		else puts("YES");
	}
	return 0;
}
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std; 
const int maxn=201000;
int n,k,len;
char s[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	n=read();k=read();
	for(register int i=0;i<k;++i){
		s[++len]='a'+i;
		for(register int j=i+1;j<k;++j){
			s[++len]='a'+i;
			s[++len]='a'+j;
		}
	}
	for(register int i=1;i<=n;++i)
		putchar(s[(i-1)%len+1]);
	return 0;
}
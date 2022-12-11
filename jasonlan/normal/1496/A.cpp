#include<iostream>
#include<cstdio>
using namespace std;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	int T=read();
	while(T--){
		int n=read(),m=read();
		string s;
		cin>>s;
		if(!m)puts("YES");
		else if(n%2==0&&m==n/2)puts("NO");
		else{
			bool flag=true;
			for(int i=0;i<m;++i)
				if(s[i]!=s[n-i-1]){
					flag=false;break;
				}
			puts(flag?"YES":"NO");
		}
	}
	return 0;
}
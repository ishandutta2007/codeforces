#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
string s;
int lftbuck,stand[128];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch=='-'?-res:res;
}
bool islegal(){
	lftbuck=0;
	for(int i=0;i<s.length();++i)
		if(stand[s[i]-'A']==1)++lftbuck;
		else if((--lftbuck)<0)return false;
	return lftbuck==0;
}
bool check(){
	for(int i=0;i<2;++i)
		for(int j=0;j<2;++j)
			for(int k=0;k<2;++k){
				stand[0]=i;
				stand[1]=j;
				stand[2]=k;
				if(islegal())return true;
			}
	return false;
}
int main(){
	int T=read();
	while(T--){
		cin>>s;
		puts(check()?"YES":"NO");
	}
	return 0;
}
#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
const int maxn=201010;
int n,m;
int cnt0,cnt1;
string s;
map <int,int> mp[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	n=read();m=read();
	for(int i=0,u,v,op;i<m;++i){
		cin>>s;
		if(s[0]=='?'){
			u=read();
			if((u-1)&1)puts(cnt1?"YES":"NO");
			else puts(cnt0?"YES":"NO");
		}
		else if(s[0]=='+'){
			u=read();v=read();
			cin>>s;
			mp[u][v]=s[0]-'a'+1;
			if(mp[v][u]){
				++cnt0;
				if(mp[v][u]==mp[u][v])
					++cnt1;
			}
		}
		else{
			u=read();v=read();
			if(mp[v][u]){
				--cnt0;
				if(mp[v][u]==mp[u][v])
					--cnt1;
			}
			mp[u][v]=0;
		}
	}
	return 0;
}
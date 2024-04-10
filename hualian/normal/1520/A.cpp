#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
bool vis[N];
char s[N];
int main(){
	int t=read();
	while(t--){
		int n=read(),f=1;
		memset(vis,0,sizeof vis);
		scanf("%s",s+1);
		for(int i=1;i<=n;i++){
			if(s[i]!=s[i-1]){
				if(vis[s[i]]){
					f=0;break;
				}
				vis[s[i]]=1;	
			}
		}
		if(f)puts("YES");
		else puts("NO");
	}
	return 0;
}
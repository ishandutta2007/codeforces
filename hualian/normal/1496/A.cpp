#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int main(){
	int t;cin>>t;string s;
	while(t--){
		int n,k;
		n=read(),k=read();
		cin>>s;
		if(2*k+1>n){
			puts("NO");
			continue;
		}
		int f=1;
		for(int i=0;i<k;i++)
			if(s[i]!=s[n-i-1]){
				f=-1;
				break;
			}
		puts(f==1?"YES":"NO");
	}
	return 0;
}
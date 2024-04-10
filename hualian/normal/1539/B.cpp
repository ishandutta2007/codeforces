#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
const int N=1e5+10;
char a[N];int s[N];
signed main(){
	int n=read(),q=read();
	scanf("%s",a+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i]-'a'+1;
	while(q--){
		int l=read(),r=read();
		printf("%d\n",s[r]-s[l-1]);
	}
	return 0;
}
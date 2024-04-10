#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+9;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
signed main(){
	int t=read();
	while(t--){
		int a=read(),b=read(),d=read();
		int l=abs(a-b);
		if(l%min(a,b))l=l/min(a,b),l++;
		else l=l/min(a,b);
		if(l>d)puts("NO");
		else puts("YES");
	}
	return 0;
}
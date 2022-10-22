#include<bits/stdc++.h>
#define int long long
#define reg register
#define For(i,a,b) for(reg int i=(a),i##END=(b);i<=i##END;i++)
using namespace std;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
const int N=1e3+10;
int a[N],b[N],t[N];
signed main(){
	int T=read();
	while(T--){
		int n=read();
		For(i,1,n)a[i]=read(),b[i]=read();
		For(i,1,n)t[i]=read();
		int now=0;
		For(i,1,n){
			now+=(a[i]-b[i-1]+t[i]);
			if(i==n){printf("%lld\n",now);break;}
			now+=(b[i]-a[i]+1)/2;
			now=max(now,b[i]);
		}
	} 
	return 0;
}
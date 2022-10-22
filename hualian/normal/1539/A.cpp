#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define int long long
using namespace std;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
signed main(){
	int T=read();
	while(T--){
		int n=read(),x=read(),t=read();
		int d=t/x;
		n--;
		d=min(d,n);
		cout<<d*(d+1)/2+(n-d)*d<<endl;
	}
	return 0;
}
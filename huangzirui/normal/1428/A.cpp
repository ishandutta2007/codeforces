#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,sx,sy,ex,ey; 
int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9') {if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0' && ch<='9') {x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
signed main() {
	T=read();
	while(T--) {
		sx=read();sy=read();ex=read();ey=read();
		if (sx==ex || sy==ey) cout<<abs(sx-ex)+abs(sy-ey)<<endl;
		else cout<<abs(sx-ex)+abs(sy-ey)+2<<endl;
	}
	return 0;
}
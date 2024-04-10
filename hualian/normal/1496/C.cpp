#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+9;
int X[N],Y[N],XX,YY;
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
		int n=read();
		XX=YY=0;
		for(int i=1;i<=2*n;i++){
			int x=read(),y=read();
			if(!x)Y[++YY]=abs(y);
			else X[++XX]=abs(x);
		}
		sort(X+1,X+1+XX);
		sort(Y+1,Y+1+YY);
		double ans=0;
		for(int i=1;i<=n;i++){
			ans+=sqrt(X[i]*X[i]+Y[i]*Y[i]);
		}
		printf("%.10lf\n",ans);
	}
	return 0;
}
#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=1e6+9;
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,ans;
int a[N],top;
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read();
	rep(i,n){
		int x=read();
		while(top>1&&x>=a[top]&&a[top]<=a[top-1])ans+=min(a[top-1],x),top--;
		a[++top]=x;
	}
	if(top<=2);
	else{
		rep(i,top)ans+=a[i];sort(a+1,a+1+top);
		ans-=a[top];ans-=a[top-1];	
	}
	cout<<ans<<endl;
	return 0;
}
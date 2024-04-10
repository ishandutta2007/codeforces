#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=2e5+9;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x;
}
int n,ans,a[N],vis[N];
int main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read();int all=n;
	rep(i,n)a[i]=read(),vis[a[i]]=1;
	Rof(k,100000,0)if(vis[k]){
		int now=0;
		rep(i,n)if(a[i]==k)all--;
		rep(i,n){
			if(a[i]==k)ans+=min(now,all-now);
			if(a[i]==k)a[i]=-1;
			if(a[i]!=-1)now++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
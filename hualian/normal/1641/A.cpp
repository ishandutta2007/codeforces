#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=2e5+9;
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int m,n,T;
int a[N],g[N];
multiset<int>s;
signed main(){
	T=read();
	while(T--){
		n=read(),m=read();s.clear();
		rep(i,n)a[i]=read();
		sort(a+1,a+n+1,[&](int x,int y){return x>y;});
		rep(i,n){
			auto it=s.find(a[i]*m);
			if(it==s.end())s.insert(a[i]);
			else s.erase(it);
		}
		printf("%lld\n",(int)s.size());
	}
	return 0;
}
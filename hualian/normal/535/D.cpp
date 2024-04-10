#include<bits/stdc++.h>
#define int long long 
#define For(i,a,b) for(register int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(register int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(register int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int p=1e9+7;
const int N=1e6+9;
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
char In[1<<20],*Ss=In,*Tt=In;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,m,q,ans=1;
int a[N],nt[N],vis[N];
char s[N];
void kmp(){
	int j=0;
	For(i,2,m){
		while(j&&s[i]!=s[j+1])j=nt[j];
		nt[i]=(s[i]==s[j+1]?++j:j);
	}
	int x=m;
	while(x)vis[x]=1,x=nt[x];
	return;
}
void WA(){puts("0");exit(0);}
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),q=read();scanf("%s",s+1);m=strlen(s+1);
	rep(i,q)a[i]=read();sort(a+1,a+1+q);
	kmp();
	if(a[q]+m-1>n)WA();
//	cout<<<<endl;
	rep(i,q-1)if(a[i]+m-1>=a[i+1]){
		if(!vis[a[i]+m-a[i+1]])WA();
	}
	memset(vis,0,sizeof vis);
	rep(i,q)vis[a[i]]++,vis[a[i]+m]--;
	rep(i,n)vis[i]+=vis[i-1];
	rep(i,n)if(!vis[i])ans=ans*26%p;
	cout<<ans<<endl;
	return 0;
}
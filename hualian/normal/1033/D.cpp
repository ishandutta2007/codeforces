#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int N=1e5+9;
const int p=998244353;
//char buf[(1<<21)+5],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void chmx(int &x,int y){(x<y)&&(x=y);}
void chmn(int &x,int y){(x>y)&&(x=y);}
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int sta[N],top,n,a[N];
unordered_map<int,int>mp;
int check2(int a){
	int x=sqrt(a);
	For(i,max(x-10,0ll),x+10)if(i*i==a)return i;
	return 0;
}
int check3(int a){
	int x=cbrt(a);
	For(i,max(x-10,0ll),x+10)if(i*i*i==a)return i;
	return 0;
}
void insert(int x,int cnt){
	if(!mp[x])sta[++top]=x;
	mp[x]+=cnt;
}
int vis[N];
long long ans=1;
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	n=read();
	rep(i,n)a[i]=read();
	rep(i,n)if(!vis[i]){
		int x=0,f=0;
		x=check2(a[i]);if(x){
			x=check2(x);if(x)insert(x,4);
			else insert(check2(a[i]),2);
			f=1;
		}
		x=check3(a[i]);if(x)insert(x,3),f=1;
		if(f)continue;//
		rep(j,top){
			int x=__gcd(sta[j],a[i]);
			if(x!=1){insert(x,1),insert(a[i]/x,1),f=1;break;}
		}if(f)continue;
		int cnt=1;
		For(j,i+1,n){
			int x=__gcd(a[i],a[j]);
			if(x!=1){
				if(x==a[i])cnt++;
				else {insert(x,1);insert(a[i]/x,1);f=1;break;}
			}
		}if(f)continue;
		ans*=(cnt+1)*(cnt+1)%p;ans%=p;
		For(j,i+1,n)if(a[i]==a[j])vis[j]=1;
	}
	rep(i,top)ans*=mp[sta[i]]+1,ans%=p;
	cout<<ans<<endl;
	return 0;
}
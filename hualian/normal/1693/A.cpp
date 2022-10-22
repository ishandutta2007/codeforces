#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int N=2e5+10;
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
int a[N],m,n,cnt,tot,sum;
bool f;
signed main(){
	int T=read();
	while(T--){
		n=read();
		sum=0;
		rep(i,n)a[i]=read(),sum+=a[i];
		if(sum){puts("No");continue;}
		cnt=0;f=false;
		tot=0;
		Rof(i,n,1){
			if(a[i])f=true;
			cnt+=(((sum+=a[i])>=0&&f));
		}
		if(cnt<2)puts("Yes");
		else puts("No");
	}
	return 0;
}
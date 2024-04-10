#include<bits/stdc++.h>
#define pi pair<int,int>
#define fi first
#define se second
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=4e5+10;
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
inline int read(){
	int fi=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){fi|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return fi?-x:x;
}
int a[N];
pi change[N];int clen;
int ans[N];int tp;
int sta[N],top;
int stk[30],TP;
void write(int x){
	do stk[++TP]=x%10,x/=10;while(x);
	while(TP)putchar(stk[TP--]^48);
}
signed main(){
	int T=read();while(T--){
		int n=read();rep(i,n)a[n-i+1]=read();
		bool flag=0;
		int sum=0,anslen=0;clen=0;
		top=0,tp=0;
		while(n){
			top=0;int j=n-1;
			while(j>=1&&a[j]!=a[n])j--;
			if(j){
				int len=n-j;
				Rof(i,n-1,j+1){
					sta[++top]=a[i];
					change[++clen]=make_pair(anslen*2+len+n-i,a[i]);
				}
				ans[++tp]=len;
				anslen+=len;
				n=j-1;
				rep(i,top)a[++n]=sta[i];
				top=0;
			}
			else{puts("-1");flag=1;break;}
		}
		if(flag)continue;
		write(clen);puts("");
		rep(i,clen)write(change[i].fi),putchar(' '),write(change[i].se),putchar('\n');
		write(tp);puts("");
		rep(i,tp)write(ans[i]*2),putchar(' ');
		puts("");
	}
	return 0;
}
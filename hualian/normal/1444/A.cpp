#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
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
int t;
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	t=read();
	while(t--){
		int x1=read(),x2=read();
		int y=x2;
		int ans=-1;
		if(x1%x2){cout<<x1<<endl;continue;}
		for(int i=2;i*i<=y;i++){
			int cnt=0;
			while(y%i==0)y/=i,cnt++;
			if(!cnt)continue;
			int X=x1;
			while(X%i==0)X/=i;
			rep(j,cnt-1)X*=i;
			chmx(ans,X);
		}
		if(y!=1){
			int X=x1;
			while(X%y==0)X/=y;
			chmx(ans,X);
		}
		
		cout<<ans<<endl;
	}
	return 0;
}
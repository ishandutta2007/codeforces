#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int N=1e3+9;
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
int T,n;
int a[N][N];
int b[N][N];
char s[N];
void check(int &x1,int &x2,int &x3){
	int m=strlen(s+1);
	rep(i,m){
		switch(s[i]){
			case 'U':{x1--;break;}
			case 'D':{x1++;break;}
			case 'L':{x2--;break;}
			case 'R':{x2++;break;}
			case 'I':{swap(x2,x3);break;}
			case 'C':{swap(x1,x3);break;}
		}
	}
}
int to[4],del[4];
int v[4];
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	T=read();
	while(T--){
		n=read();int p=read();
		rep(i,n)rep(j,n)a[i][j]=read();
		scanf("%s",s+1);
		int x1=0,x2=-1e9,x3=-1e9;
		check(x1,x2,x3);
		if(x1>-1e8)to[1]=1,del[1]=x1;
		if(x2>-1e8)to[1]=2,del[1]=x2;
		if(x3>-1e8)to[1]=3,del[1]=x3;
		
		x1=-1e9,x2=0,x3=-1e9;
		check(x1,x2,x3);
		if(x1>-1e8)to[2]=1,del[2]=x1;
		if(x2>-1e8)to[2]=2,del[2]=x2;
		if(x3>-1e8)to[2]=3,del[2]=x3;
		
		x1=-1e9,x2=-1e9,x3=0;
		check(x1,x2,x3);
		if(x1>-1e8)to[3]=1,del[3]=x1;
		if(x2>-1e8)to[3]=2,del[3]=x2;
		if(x3>-1e8)to[3]=3,del[3]=x3;
		rep(i,n)rep(j,n){
			int x1=0,x2=0,x3=0;
			v[1]=i;v[2]=j;v[3]=a[i][j];
			rep(x,3)if(to[x]==1)x1=del[x]+v[x];
			rep(x,3)if(to[x]==2)x2=del[x]+v[x];
			rep(x,3)if(to[x]==3)x3=del[x]+v[x];
			x1--;x2--;x3--;
			((x1%=n)+=n)%=n;
			((x2%=n)+=n)%=n;
			((x3%=n)+=n)%=n;
			b[x1+1][x2+1]=x3+1;
		}
		rep(i,n){rep(j,n)printf("%d ",b[i][j]);puts("");}
	}
	return 0;
}
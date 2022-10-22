#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int N=2e5+9;
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
int n,q,cnt; 
int t[3][N];
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),q=read();
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		--x;
		t[x][y]^=1;
		if(t[x^1][y-1]) cnt+=t[x][y]?1:-1;
		if(t[x^1][y]) cnt+=t[x][y]?1:-1;
		if(t[x^1][y+1]) cnt+=t[x][y]?1:-1;
		puts(cnt>0?"NO":"YES");
	}
	return 0;
}
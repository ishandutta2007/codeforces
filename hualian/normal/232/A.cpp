#include<bits/stdc++.h>
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
int m,mp[110][110];
int C3(int n){return n*(n-1)*(n-2)/3/2/1;}
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	m=read();int rt=0;
	Rof(i,100,1){
		if(C3(i)<=m){rt=i;break;}
	}m-=C3(rt);
	rep(i,rt)rep(j,rt)mp[i][j]=1;
	int idx=rt;
	while(m){
		++idx;mp[idx][1]=mp[1][idx]=1;
		rep(i,rt-1)if(m>=i)m-=i,mp[idx][i+1]=mp[i+1][idx]=1;else break;
	}cout<<idx<<endl;
	rep(i,idx){rep(j,idx){
		putchar(i==j?'0':mp[i][j]+'0');
	}puts("");}
	return 0;
}
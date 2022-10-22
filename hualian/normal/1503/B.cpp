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
int n;
struct node{
	int x,y;
}A[N],B[N];int a,b;
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	n=read();
	rep(i,n)rep(j,n){
		if((i+j)&1)A[++a]=node{i,j};
		else B[++b]=node{i,j};
	}
	rep(k,n*n){
		int x=read();
		if(x==3){
			if(a){
				printf("1 %d %d\n",A[a].x,A[a].y);
				a--;
			}else if(b){
				printf("2 %d %d\n",B[b].x,B[b].y);
				b--;
			}
		}
		else if(x!=1){
			if(a){
				printf("1 %d %d\n",A[a].x,A[a].y);
				a--;
			}else{
				printf("3 %d %d\n",B[b].x,B[b].y);
				b--;
			}
		}else if(x!=2){
			if(b){
				printf("2 %d %d\n",B[b].x,B[b].y);
				b--;
			}else{
				printf("3 %d %d\n",A[a].x,A[a].y);
				a--;
			}
		}
		fflush(stdout);
	}
	return 0;
}
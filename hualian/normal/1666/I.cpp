#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define endout fflush(stdout)
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
int X1,Y1,X2,Y2;
int answer(int x,int y){
	printf("DIG %d %d\n",x,y),endout;
//	return (X1==x&&Y1==y)||(X2==x&&Y2==y);
	return read();
}
int qry(int x,int y){
	printf("SCAN %d %d\n",x,y),endout;
//	return abs(X1-x)+abs(X2-x)+abs(Y1-y)+abs(Y2-y);
	return read();
}
signed main(){
	int T=read();while(T--){
//		X1=read(),Y1=read(),X2=read(),Y2=read();
		int n=read(),m=read();
		int A=qry(1,1)+4,B=qry(1,m)+2-2*m;
		int sumx=(A+B)/2,sumy=(A-B)/2;
		int delx=qry(sumx/2,1)+2-sumy;
		int dely=qry(1,sumy/2)+2-sumx;
		int x1=(sumx+delx)/2,x2=(sumx-delx)/2;
		int y1=(sumy+dely)/2,y2=(sumy-dely)/2;
		if(answer(x1,y1))answer(x2,y2);
		else answer(x1,y2),answer(x2,y1);
	}
	return 0;
}
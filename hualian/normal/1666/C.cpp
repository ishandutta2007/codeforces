#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
struct node{
	int x,y;
	bool operator <(const node &a) const {return y<a.y;}
}a[3];
struct seg{
	int x1,x2,y1,y2;
}stk[50];int tp;
signed main(){
	For(i,0,2)a[i].x=read(),a[i].y=read();sort(a,a+3);
	int mnx=min({a[0].x,a[1].x,a[2].x}),mxx=max({a[0].x,a[1].x,a[2].x}); 
	int mny=min({a[0].y,a[1].y,a[2].y}),mxy=max({a[0].y,a[1].y,a[2].y}); 
	if(a[0].x==a[1].x&&a[1].x==a[2].x){
		puts("1");
		printf("%d %d %d %d\n",a[0].x,mny,a[0].x,mxy);
		return 0;
	}
	stk[++tp]=(seg){mnx,mxx,a[1].y,a[1].y};
	if(a[0].y!=a[1].y)stk[++tp]=(seg){a[0].x,a[0].x,min(a[0].y,a[1].y),max(a[0].y,a[1].y)};
	if(a[2].y!=a[1].y)stk[++tp]=(seg){a[2].x,a[2].x,min(a[2].y,a[1].y),max(a[2].y,a[1].y)};
	cout<<tp<<endl;
	For(i,1,tp)printf("%d %d %d %d\n",stk[i].x1,stk[i].y1,stk[i].x2,stk[i].y2);
	return 0;
}
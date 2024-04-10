//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=1.5e5+5,mod=998244353;
int pw[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
inline int add(int x){return (x>=mod)?x-mod:x;}
inline void add(int &x,int y){x=add(x+y);return ;}
inline int sub(int x){return (x<0)?x+mod:x;}
struct node{int ls,rs,siz;}t[30*maxn];
int tot=1;
void ins(int x){
	int k=1;t[1].siz++;
	for(int i=29;i>=0;i--){
		int to=(x>>i)&1;
		if(to&&!t[k].rs)t[k].rs=++tot;
		if(!to&&!t[k].ls)t[k].ls=++tot;
		if(to)k=t[k].rs;else k=t[k].ls;
		t[k].siz++;
	}
	return ;
}
int v;
int F(int x,int y,int d){
	if(!x)return pw[t[y].siz];
	if(!y)return pw[t[x].siz];
	if(d==-1){
		if(x==y)return pw[t[x].siz];
		return pw[t[x].siz+t[y].siz];
	}
	int c=(v>>d)&1;
	int xls=t[x].ls,xrs=t[x].rs;
	int yls=t[y].ls,yrs=t[y].rs;
	if(c){
		if(x==y)return F(xls,xrs,d-1);
		else return 1ll*F(xls,yrs,d-1)*F(xrs,yls,d-1)%mod;
	}
	else{
		if(x==y)return sub(add(F(xls,xls,d-1)+F(xrs,xrs,d-1))-1);
		else{
			int w=sub(add(F(xls,yls,d-1)+F(xrs,yrs,d-1))-1);
			add(w,1ll*sub(pw[t[xls].siz]-1)*sub(pw[t[xrs].siz]-1)%mod);
			add(w,1ll*sub(pw[t[yls].siz]-1)*sub(pw[t[yrs].siz]-1)%mod);
			return w;
		}
	}
}
int main(){
    int n;
	n=read();v=read();
	pw[0]=1;for(int i=1;i<=n;i++)pw[i]=add(pw[i-1]+pw[i-1]);
	for(int i=1;i<=n;i++)ins(read());
	printf("%d\n",sub(F(1,1,29)-1));
    return 0;
}
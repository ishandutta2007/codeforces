//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
typedef __int128 lll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=1005;
lll a[maxn],b[maxn];
lll read(){
    lll x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
void write(lll x){
	if(!x)return ;
	write(x/10);
	putchar('0'+x%10);
	return ;
}
inline lll gcd(lll x,lll y){return (y==0)?x:gcd(y,x%y);}
lll buf[maxn];
struct SMT{
	lll g[4*maxn];
	void build(int k,int l,int r){
		if(l==r){g[k]=buf[l];return ;}
		int mid=l+((r-l)>>1);
		build(k<<1,l,mid);build(k<<1|1,mid+1,r);
		g[k]=gcd(g[k<<1],g[k<<1|1]);
		return ;
	}
	void del(int k,int l,int r,int x){
		if(l==r){g[k]=0;return ;}
		int mid=l+((r-l)>>1);
		if(x<=mid)del(k<<1,l,mid,x);
		else del(k<<1|1,mid+1,r,x);
		g[k]=gcd(g[k<<1],g[k<<1|1]);
		return ;
	}
}T[2][maxn];
bool bana[maxn],banb[maxn];
int main(){
    int C;
	C=read();
	while(C--){
		int n,m;
		n=read();m=read();
		for(int i=1;i<=n;i++)a[i]=read(),bana[i]=0;
		for(int i=1;i<=m;i++)b[i]=read(),banb[i]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)buf[j]=a[i]/gcd(a[i],b[j]);
			T[0][i].build(1,1,m);
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++)buf[j]=b[i]/gcd(b[i],a[j]);
			T[1][i].build(1,1,n);
		}
		int numa=n,numb=m;
		while(1){
			int x=0;
			for(int i=1;i<=n;i++)if(!bana[i]&&T[0][i].g[1]>1){x=i;break;}
			if(x){
				bana[x]=1;numa--;
				for(int i=1;i<=m;i++)T[1][i].del(1,1,n,x);
				continue;
			}
			for(int i=1;i<=m;i++)if(!banb[i]&&T[1][i].g[1]>1){x=i;break;}
			if(x){
				banb[x]=1;numb--;
				for(int i=1;i<=n;i++)T[0][i].del(1,1,m,x);
				continue;
			}
			break;
		}
		if(!numa||!numb){puts("NO");continue;}
		puts("YES");
		printf("%d %d\n",numa,numb);
		for(int i=1;i<=n;i++)if(!bana[i])write(a[i]),putchar(' ');
		puts("");
		for(int i=1;i<=m;i++)if(!banb[i])write(b[i]),putchar(' ');
		puts("");
	}
    return 0;
}
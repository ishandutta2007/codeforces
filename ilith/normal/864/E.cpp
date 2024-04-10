#include<bits/stdc++.h>
#define int long long
#define rgi register int
typedef long long ll;
using namespace std;
inline void read(){}template <typename T,typename... Ts> inline void read(T& A,Ts&... As){
	T x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	A=x*f,read(As...);
}
inline void write(char a){putchar(a);}
template <typename T> inline void write(T a){
	if(a<0ll)putchar('-'),a=-a;
	if(a>9ll)write(a/10ll);
	putchar(a%10ll+'0');
}
template <typename T,typename... Ts> inline void write(T A,Ts... As){write(A),write(As...);}
int n,ans;
struct node{
	int t,d,p,id;
}a[110];
bool operator<(node x,node y){
	return x.d<y.d;
}
int ax,ay;
int f[110][20010];//ij 
int c[110][20010];
int ced[110][20010];
int to[110][20010];
int s[110],cnt;
signed main(){
	read(n);
	for(rgi i=1;i<=n;++i){
		read(a[i].t,a[i].d,a[i].p),a[i].id=i;
	}
	sort(a+1,a+n+1);
	for(rgi i=1;i<=n;++i){
		for(int j=1;j<=2000;++j){
			f[i][j]=f[i-1][j],c[i][j]=c[i-1][j],ced[i][j]=0;
			to[i][j]=j;
			if(a[i].d>j&&j>=a[i].t){
				if(f[i-1][j-a[i].t]+a[i].p>f[i][j]){
					f[i][j]=f[i-1][j-a[i].t]+a[i].p;
					c[i][j]=c[i-1][j-a[i].t]+1;
					ced[i][j]=1;
					to[i][j]=j-a[i].t;
				}
				if(f[i][j]>ans)ans=f[i][j],ax=i,ay=j;
			}
		}
	}
	write(ans,'\n',c[ax][ay],'\n');
	while(ax){
		if(ced[ax][ay])s[++cnt]=a[ax].id;
		ay=to[ax][ay];
		--ax;
	}
	for(rgi i=cnt;i>=1;--i)write(s[i],' ');
	return 0;
}
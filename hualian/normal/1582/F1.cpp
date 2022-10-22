#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
//#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=1e5+10;
int n,a[N],f[600],g[600];
inline void gmin(int &a,int b){(a>b)&&(a=b);}
signed main(){
	int T=1;while(T--){
		For(i,1,n=read())a[i]=read();
		memset(f,0x3f,sizeof f),f[0]=0;
		For(i,1,n){
			memset(g,0x3f,sizeof g);
			For(j,0,511){
				gmin(g[j],f[j]);
				if(f[j]<a[i])gmin(g[j^a[i]],a[i]);
			}
			swap(f,g);
		}int c=0;For(i,0,511)if(f[i]<=500)c++;
		printf("%d\n",c);For(i,0,511)if(f[i]<=500)printf("%d ",i);puts("");
	}
	return 0;
}
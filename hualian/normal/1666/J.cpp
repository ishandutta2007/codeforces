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
#define int long long
const int N=210;
int n,c[N][N],val[N][N],f[N][N];
inline void gmin(int &a,int b){
	(a>b)&&(a=b);
}int fa[N];
int getans(int l,int r){
	if(l>r)return 0;
	For(k,l,r){
		if(f[l][r]==f[l][k-1]+val[l][k-1]+f[k+1][r]+val[k+1][r]){
			fa[getans(l,k-1)]=k,fa[getans(k+1,r)]=k;
			return k;
		}
	}assert(0);
}
signed main(){
	n=read();For(i,1,n)For(j,1,n)c[i][j]=read();
	For(l,1,n){
		For(k,1,l-1)val[l][l]+=c[l][k];
		For(k,l+1,n)val[l][l]+=c[l][k];
		For(r,l+1,n){
			val[l][r]=val[l][r-1];
			For(k,l,r-1)val[l][r]-=c[r][k];
			For(k,1,l-1)val[l][r]+=c[r][k];
			For(k,r+1,n)val[l][r]+=c[r][k];
		}
	}memset(f,0x3f,sizeof f);
	For(i,1,n+1)f[i][i]=f[i][i-1]=0;
	For(len,2,n){
		For(l,1,n-len+1){
			int r=l+len-1;
			For(k,l,r)
				gmin(f[l][r],f[l][k-1]+val[l][k-1]+f[k+1][r]+val[k+1][r]);
		}
	}getans(1,n);For(i,1,n)printf("%lld ",fa[i]);puts("");
	return 0;
}
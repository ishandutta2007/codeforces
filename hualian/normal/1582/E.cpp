#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=1e5+10,S=450;
int n,a[N],f[N][S];
inline void gmax(int &a,int b){(a<b)&&(a=b);}
signed main(){
	int T=read();while(T--){
		n=read();int k=448;
		For(i,1,n)a[i]=a[i-1]+read();
		For(i,0,n+1)For(j,0,k)f[i][j]=0;
		f[n+1][0]=1e18;int ans=0;
		Rof(i,n+1,1)For(j,0,k)if(f[i][j]){
			gmax(f[i-1][j],f[i][j]);
			if(i-j-1<0)continue;
			if(i<=n&&a[i]-a[i-j-1]<f[i][j])gmax(f[i-j-1][j+1],a[i]-a[i-j-1]);
		}For(i,0,k)if(f[0][i])ans=i;
//		For(i,0,k)printf("f[0][%d] = %lld\n",i,f[0][i]);
		printf("%lld\n",ans);
	}
	return 0;
}
//#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define ll long long
//#define I inline
//#define R register int
namespace io{
    const int l=1<<19;
    char buf[l],*s,*t,c;
    char gc(){
        if(s==t){
            t=(s=buf)+fread(buf,1,l,stdin);
            return s==t?EOF:*s++;
        }
        return *s++;
    }
    template<class IT>void gi(IT &x){
        x=0;c=gc();while(c<'0'||c>'9')c=gc();
        while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=gc();}
    }
};
using io::gi;
template<class IT>void chkmin(IT &a,IT b){if(b<a)a=b;}
template<class IT>void chkmax(IT &a,IT b){if(a<b)a=b;}

const int N=300005,K=20;

int n,q,x,y,f,a[N],fi[K],dp[N][K];
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int j=0;j<K;j++)dp[0][j]=N;
	for(int i=n;i>=1;i--){
		for(int j=0;j<K;j++)dp[i][j]=N;
		for(int j=0;j<K;j++){
			if(((a[i]>>j)&1)==1){
				dp[i][j]=i;
				for(int k=0;k<K;k++)chkmin(dp[i][k],dp[fi[j]][k]);
				fi[j]=i;
			}
		}
	}
//	for(int i=1;i<=n;i++){for(int j=0;j<2;j++)printf("%d ",dp[i][j]);printf("\n");}
	for(int Q=1;Q<=q;Q++){
		scanf("%d%d",&x,&y);
		f=0;
		for(int j=0;j<K;j++)if((a[y]>>j)==1&&dp[x][j]<=y){f=1;break;}
		if(f==1)puts("Shi");else puts("Fou");
	}
	return 0;
}
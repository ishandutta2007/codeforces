#include<cstring> 
#include<cstdio>
#include<algorithm>
#define fo(i,a,b)for(int i=a,E=b;i<=E;i++)
#define fd(i,a,b)for(int i=b,E=a;i>=E;i--)
#define ll long long
#define db long double
#define pu(x)putchar(x)
#define min(a,b)(a<b?a:b)
using namespace std;
const int N=5005;
int n,a[N],x;
ll f[N][N>>1][3],ans;
bool bz;
void R(int &n){
	char c;for(n=0;(c=getchar())<'0'||c>'9';);
	for(;c<='9'&&c>='0';c=getchar())n=n*10+c-48;
}
int main(){
//	freopen("2.in","r",stdin);
//	freopen("1.out","w",stdout);
	R(n);
	fo(i,0,n)fo(j,0,i+1>>1)f[i][j][0]=f[i][j][1]=f[i][j][2]=1e18;
	f[0][0][0]=0;
	fo(i,1,n){
		R(a[i]);
		fo(j,0,i>>1){
			if(f[i-1][j][0]<1e18){
				f[i][j][0]=min(f[i][j][0],f[i-1][j][0]);
				x=a[i-1]-min(a[i]-1,a[i-1]);
				f[i][j+1][1]=min(f[i][j+1][1],f[i-1][j][0]+x);
			}
			if(f[i-1][j][1]<1e18){
				x=a[i]-min(a[i-1]-1,a[i]);
				f[i][j][2]=min(f[i][j][2],f[i-1][j][1]+x);
			}
			if(f[i-1][j][2]<1e18){
				f[i][j][0]=min(f[i][j][0],f[i-1][j][2]);
				x=min(a[i-2]-1,a[i-1]);
				x=x-min(x,a[i]-1);
				f[i][j+1][1]=min(f[i][j+1][1],f[i-1][j][2]+x);
			}
		}
	}
	fo(i,1,n+1>>1){
		ans=min(f[n][i][0],f[n][i][1]);
		ans=min(ans,f[n][i][2]);
		printf("%I64d ",ans);
	}
}
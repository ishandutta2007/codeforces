#include <bits/stdc++.h>
#define LL long long
#define ull unsigned long long
#define LD long double
using namespace std;
const int N=3e5+10;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
int n;
int mx[105];
int f[105][105*105];
bool vis[105][105*105];
long double ans[105];
int main(){
	scanf("%d",&n);
	int a,b,s=0;
	vis[0][0]=1;
	for(int i=1;i<=n;++i){
		scanf("%d%d",&a,&b);s+=b;
		for(int j=i;j>0;--j) mx[j]=max(mx[j],mx[j-1]+a);
		for(int j=i;j>0;--j){
			for(int k=mx[j];k>=a;--k){
				if(vis[j-1][k-a]){
					vis[j][k]|=vis[j-1][k-a];
					f[j][k]=max(f[j][k],f[j-1][k-a]+b);
				}
			}
		}
	}
	for(int j=1;j<=n;++j){
		ans[j]=0;
		for(int k=0;k<=mx[j];++k){
			if(vis[j][k]){
				//cout<<j<<" "<<k<<" "<<f[j][k]<<endl;
				ans[j]=max(ans[j],min((LD)k,(LD)(f[j][k]+s)/(LD)2));
			}
		}
		printf("%0.10Lf ",ans[j]);
	}
	
	puts("");
	return 0;
}
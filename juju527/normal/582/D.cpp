//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=4005;
const int mod=1e9+7;
int p,a,n;
char s[maxn];
int A[maxn],lim[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
void trans_to_p(){
	int len=strlen(s+1);
	for(int i=1;i<=len;i++)A[i]=s[len-i+1]-'0';
	while(len){
		ll tmp=0;
		for(int i=len;i>=1;i--){
			tmp=tmp*10+A[i];
			A[i]=tmp/p;
			tmp%=p;
		}
		lim[++n]=tmp;
		while(len&&!A[len])len--;
	}
	return ;
}
inline int add(int x){return (x>=mod)?x-mod:x;}
void trans(int &x,int y){x=add(x+y);return ;}
inline int sub(int x){return (x<0)?x+mod:x;}
int f[maxn][maxn][2][2];
int main(){
	p=read();a=read();
	scanf("%s",s+1);
	trans_to_p();
	f[n+1][0][0][1]=1;
	for(int i=n;i>=1;i--){
		int k=lim[i];
		int a1=1ll*p*(p+1)/2%mod,a2=1ll*k*(k+1)/2%mod;
		int a3=1ll*p*(p-1)/2%mod;
		int a4=1ll*k*(2*p-k-1)/2%mod;
		int b1=k+1,b2=p-k-1;
		int c1=a3,c2=1ll*k*(k-1)/2%mod,c3=a1,c4=1ll*k*(2*p-k+1)/2%mod;
		int d1=k,d2=p-k;
		for(int j=0;j<=n-i;j++){
			trans(f[i][j][0][0],1ll*a1*f[i+1][j][0][0]%mod);
			trans(f[i][j][0][0],1ll*a2*f[i+1][j][0][1]%mod);
			trans(f[i][j][0][0],1ll*a3*f[i+1][j][1][0]%mod);
			trans(f[i][j][0][0],1ll*a4*f[i+1][j][1][1]%mod);

			trans(f[i][j][0][1],1ll*b1*f[i+1][j][0][1]%mod);
			trans(f[i][j][0][1],1ll*b2*f[i+1][j][1][1]%mod);
			
			trans(f[i][j+1][1][0],1ll*c1*f[i+1][j][0][0]%mod);
			trans(f[i][j+1][1][0],1ll*c2*f[i+1][j][0][1]%mod);
			trans(f[i][j+1][1][0],1ll*c3*f[i+1][j][1][0]%mod);
			trans(f[i][j+1][1][0],1ll*c4*f[i+1][j][1][1]%mod);
			
			trans(f[i][j+1][1][1],1ll*d1*f[i+1][j][0][1]%mod);
			trans(f[i][j+1][1][1],1ll*d2*f[i+1][j][1][1]%mod);
		}
	}
	int res=0;
	for(int i=a;i<=n;i++)res=add(res+add(f[1][i][0][0]+f[1][i][0][1]));
	printf("%d\n",res);
    return 0;
}
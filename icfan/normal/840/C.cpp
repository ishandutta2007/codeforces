#include <cstdio>
#include <algorithm>
using namespace std;
const int Maxn=300;
const int Mod=1000000007;
typedef long long ll;
int a[Maxn+5];
int b[Maxn+5];
int n;
int C[Maxn+5][Maxn+5];
int num[Maxn+5],sum[Maxn+5],len;
int work(int n){
	int num;
	int ans=1;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			num=0;
			while(n%i==0){
				n/=i;
				num++;
			}
			if(num&1){
				ans*=i;
			}
		}
	}
	if(n>1){
		ans*=n;
	}
	return ans;
}
int f[Maxn+5][Maxn+5];
int g[Maxn+5][Maxn+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]=work(a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]){
			b[i]=b[i-1]+1;
		}
		else{
			b[i]=b[i-1];
		}
	}
	len=b[n];
	for(int i=1;i<=n;i++){
		num[b[i]]++;
	}
	for(int i=1;i<=len;i++){
		sum[i]=sum[i-1]+num[i];
	}
	C[0][0]=1;
	for(int i=1;i<=n;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%Mod;
		}
	}
	f[0][0]=1;
	g[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			g[i][j]=(1ll*g[i-1][j]*(i-1+j)%Mod+1ll*g[i-1][j-1]*j%Mod)%Mod;
		}
	}
	for(int i=1;i<=len;i++){
		for(int j=0;j<=sum[i-1];j++){
			for(int k=1;k<=num[i];k++){
				for(int l=0;l<=j;l++){
					f[i][j+(num[i]-k)-l]=(f[i][j+(num[i]-k)-l]+1ll*f[i-1][j]*g[num[i]][k]%Mod*C[j][l]%Mod*C[sum[i-1]-j+1][k-l]%Mod)%Mod;
				}
			}
		}
	}
	printf("%d\n",f[len][0]);
	return 0;
}
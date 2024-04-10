#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Mod=998244353;
int n,c,k,a[3100],Ans[3100],cnt[3100],num[3100][3100],inv[3100],pw[3100];
int f[3100][3100],g[3100][3100];
ll qpow(ll x,int a){
	ll res=1;
	while (a){
		if (a&1) res=res*x%Mod;
		x=x*x%Mod; a>>=1;
	}
	return res;
}
void work1(){
	int upperlim=(1<<c)-1;
	g[0][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=k;j>=0;j--){
			int tmp=(1<<a[i]);
			f[j+1][i]=g[j][upperlim^tmp];
			for (int s=upperlim-1;s>=0;s--){
				if ((s|tmp)==upperlim) g[j+1][0]=(g[j+1][0]+g[j][s])%Mod;
				else g[j][s|tmp]=(g[j][s|tmp]+g[j][s])%Mod;
			}
		}
}
void work2(){
	for( int r=1;r<=n;r++){
		for (int i=1;i<=n;i++) cnt[a[i]]=0;
		cnt[a[r]]++;
		int tmp=1,t=1;
		for (int l=r-1;l>=0;l--){
			if (t==c) num[l+1][r]=tmp;
			if (a[l]!=a[r]){
				t+=(!cnt[a[l]]); cnt[a[l]]++;
				tmp=1ll*tmp*inv[cnt[a[l]]-1]%Mod*pw[cnt[a[l]]]%Mod;
			}
		}	
	}

	f[0][0]=1;
	for (int i=1;i<=k;i++)
		for (int j=1;j<=n;j++)
			for (int k=0;k<j;k++)
				if (f[i-1][k]&&num[k+1][j]) f[i][j]=(f[i][j]+1ll*f[i-1][k]*num[k+1][j])%Mod;
}
int main(){
	scanf("%d%d",&n,&c); k=n/c;
	pw[0]=0; inv[0]=1;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]),a[i]--;
		pw[i]=(pw[i-1]<<1|1)%Mod; inv[i]=qpow(pw[i],Mod-2);
	}
	if (c<=11) work1();
	else work2();
	for (int i=1;i<=k;i++)
		for (int j=1;j<=n;j++)
			Ans[i]=(Ans[i]+1ll*f[i][j]*(pw[n-j]+1))%Mod;
	Ans[0]=pw[n];
	for (int i=0;i<=n;i++) printf("%d ",(Ans[i]-Ans[i+1]+Mod)%Mod);
	return 0;
}
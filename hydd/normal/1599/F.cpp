#include<bits/stdc++.h>
using namespace std;
const int Mod=1e9+7;
const int inv2=(Mod+1)/2;
const int inv6=(Mod+1)/6;
int n,q,a[210000],pre[210000][2],inv[210000];
int getsum0(int n){
	return 1ll*n*(n+1)%Mod*inv2%Mod;
}
int getsum1(int n){
	return 1ll*n*(n+1)%Mod*(n+n+1)%Mod*inv6%Mod;
}
int calc0(int a0,int d,int n){//a0+(a0+d)+(a0+2d)+...+(a0+(n-1)d)
	return (1ll*a0*n+1ll*d*getsum0(n-1))%Mod;
}
int calc1(int a0,int d,int n){//a0^2+(a0+d)^2+(a0+2d)^2+...+(a0+(n-1)d)^2
	return (1ll*a0*a0%Mod*n+2ll*a0*d%Mod*getsum0(n-1)+1ll*d*d%Mod*getsum1(n-1))%Mod;
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>q; inv[1]=1;
	for (int i=1;i<=n;i++){
		cin>>a[i]; if (i>1) inv[i]=1ll*(Mod-Mod/i)*inv[Mod%i]%Mod;
		pre[i][0]=(pre[i-1][0]+a[i])%Mod;
		pre[i][1]=(pre[i-1][1]+1ll*a[i]*a[i])%Mod;
	}
	int l,r,d;
	for (int i=1;i<=q;i++){
		cin>>l>>r>>d;
		if (l==r){
			puts("Yes");
			continue;
		}
		int hs0=(pre[r][0]-pre[l-1][0]+Mod)%Mod;
		int hs1=(pre[r][1]-pre[l-1][1]+Mod)%Mod;
		int len=r-l+1;

		int a0=(hs0-1ll*getsum0(len-1)*d%Mod+Mod)%Mod*inv[len]%Mod;//(sum-(0*d+1*d+2*d+...))/len
		if (calc0(a0,d,len)!=hs0||calc1(a0,d,len)!=hs1) puts("No");
		else puts("Yes");
	}
	return 0;
}
#include<cstdio>
using namespace std;
const int Mod=998244353;
int n,p[210000],tree[210000];
int s[210000],pre[210000],suf[210000],inv[210000];
void add(int x,int y){
    for (;x<=n;x+=x&-x) tree[x]+=y;
}
int getsum(int x){
    int sum=0;
    for (;x;x-=x&(-x)) sum+=tree[x];
    return sum;
}
inline int C2(int x){
	return (1ll*x*(x-1)/2)%Mod;
}
int main(){
	scanf("%d",&n); int tot=0;
	inv[1]=1; for (int i=2;i<=200000;i++) inv[i]=1ll*(Mod-Mod/i)*inv[Mod%i]%Mod;
	for (int i=1;i<=n;i++) s[i]=1;
	for (int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		if (p[i]!=-1) s[p[i]]--;
		else tot++;
	}
	for (int i=1;i<=n;i++){
		s[i]+=s[i-1];
		pre[i]=pre[i-1]+(p[i]==-1);
	}
	int now,ans=0;
	for (int i=n;i>=1;i--)
		if (p[i]==-1) suf[i]=suf[i+1]+1;
		else{
			suf[i]=suf[i+1];
			ans=(ans+getsum(p[i]))%Mod;
			add(p[i],1);
		}
	for (int i=1;i<=n;i++)
		if (p[i]!=-1){
			now=tot-s[p[i]];
			ans=(ans+1ll*pre[i]*now%Mod*inv[tot])%Mod;
			now=s[p[i]-1];
			ans=(ans+1ll*suf[i]*now%Mod*inv[tot])%Mod;
		}
	ans=(ans+1ll*C2(tot)*inv[2])%Mod;
	printf("%d\n",ans);
	return 0;
}
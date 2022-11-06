#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
  long long x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
long long tn,lst,now,b[1001010],fre[1001010],i,F[1001010],MOD,fac[1001010],inv[1001010],ifac[1001010],n,m,a[1001010],tot,G,ans;
void modify(long long x,long long y){
	for (;x<=200000;x+=x&-x) F[x]=(F[x]+y) % MOD;
}
long long query(long long x){
	long long ans=0;
	for (;x;x-=x&-x) ans=(ans+F[x]) % MOD;
	return ans;
}
int main()
{MOD=998244353;
	fac[0]=1;
	for (i=1;i<=200000;i++) fac[i]=fac[i-1]*i % MOD;inv[1]=1;inv[0]=1;
	for (i=2;i<=200000;i++) inv[i]=(MOD-MOD/i)*inv[MOD % i] % MOD;
	ifac[0]=1;
	for (i=1;i<=200000;i++) ifac[i]=ifac[i-1]*inv[i] % MOD;
	n=read();m=read();
	for (i=1;i<=n;i++) a[i]=read(),fre[a[i]]++;
    for (i=1;i<=200000;i++) if (fre[i]>0)modify(i,fre[i]);
	tot=fac[n];
	for (i=1;i<=200000;i++) tot=tot*ifac[fre[i]] % MOD;
	for (i=1;i<=m;i++) b[i]=read();
	if (n<=m) {tn=n;
		for (i=1;i<=n;i++)
		     {
		        G=query(b[i]-1);
		        if (i==n) {
		        	ans+=G;
		        	if (fre[b[i]]==0) break;
		        	if (n<m) ans++;
					break;
				}
				ans=(ans+tot*inv[tn] % MOD*G % MOD) % MOD;
				tot=tot*inv[tn] % MOD;
				tn--;
			    if (fre[b[i]]==0) break;
			    /*lst=fre[b[i]]*inv[fre[b[i]]-1] % MOD;
			    if (fre[b[i]]==1) now=0;else now=(fre[b[i]]-1)*inv[fre[b[i]]-2] % MOD;
			    modify(b[i],(-lst+now+MOD) % MOD);*/
			    modify(b[i],MOD-1);
			    tot=tot*fre[b[i]] % MOD;
			    fre[b[i]]--;
			 }
	}
	else{tn=n;
		for (i=1;i<=m;i++)
		     {
		        G=query(b[i]-1);
				ans=(ans+tot*inv[tn] % MOD*G % MOD) % MOD;
				
				tot=tot*inv[tn] % MOD;
				tn--;
			    if (fre[b[i]]==0) break;
			    /*lst=fre[b[i]]*inv[fre[b[i]]-1] % MOD;
			    if (fre[b[i]]==1) now=0;else now=(fre[b[i]]-1)*inv[fre[b[i]]-2] % MOD;
			    modify(b[i],(-lst+now+MOD) % MOD);*/
			    modify(b[i],MOD-1);
			    tot=tot*fre[b[i]] % MOD;
			    fre[b[i]]--;
			 }
	}
	printf("%lld\n",ans % MOD);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((ch!='-')&&(!isdigit(ch))) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
bool prim[1001010];
long long MOD,tum,tot,vv,n,m,i,j,k,num[1001010],ans,sum;
int main() {
	n=read();m=read();
	MOD=998244353;
	for (i=2;i<=n;i++)
       if (prim[i]==false)
          for (j=i;j<=n/i;j++)
              prim[i*j]=true;
	ans=1;vv=1;tum=1;
	for (i=1;i<=n;i++){
		vv=vv*(m % MOD) % MOD;
		if ((prim[i]==false)&&(tum<=m)) tum=tum*i;
		num[i]=m/tum;
		num[i]=num[i] % MOD;
	ans=ans*num[i] % MOD;
	sum=(sum+ans) % MOD;
	tot=(tot+vv) % MOD;
	}
	tot=tot-sum;
	tot=(tot+MOD) % MOD+MOD;
	tot=tot % MOD;
	cout<<tot<<endl;
	return 0;
}
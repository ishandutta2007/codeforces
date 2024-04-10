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
long long C[1010][1010],k,A[1010][1010],B[1010][1010],K,j,MOD,n,f[11][210],now,i,a[1001010],G,Q,lft,rit,tot0,tot1;
long long pow(long long x,long long y,long long p){long long ans=1;for (;y;y>>=1,x=x*x % p) if (y&1) ans=ans*x % MOD;return ans;}
void MulB(){
	for (i=0;i<=tot0;i++)
	   for (j=0;j<=tot0;j++) 
	       C[i][j]=0;
    for (k=0;k<=tot0;k++)
      for (i=0;i<=tot0;i++)
         for (j=0;j<=tot0;j++)
             C[i][j]=(C[i][j]+B[i][k]*B[k][j]) % MOD;
    for (i=0;i<=tot0;i++)
       for (j=0;j<=tot0;j++)
            B[i][j]=C[i][j];
}
void MulA(){
	for (i=0;i<=0;i++)
	   for (j=0;j<=tot0;j++) 
	       C[i][j]=0;
    for (k=0;k<=tot0;k++)
      for (i=0;i<=0;i++)
         for (j=0;j<=tot0;j++)
             C[i][j]=(C[i][j]+A[i][k]*B[k][j]) % MOD;
    for (i=0;i<=0;i++)
       for (j=0;j<=tot0;j++)
            A[i][j]=C[i][j];
}
int main()
{
	n=read();K=read();MOD=1e9+7;
	for (i=1;i<=n;i++) a[i]=read(),tot1+=a[i];
	tot0=n-tot1;
	if ((tot0==0)||(tot1==0)){puts("1");return 0;}
	for (i=1;i<=tot0;i++) lft+=a[i],rit+=1-a[i];
	G=n*(n-1)/2;G%=MOD;G=pow(G,MOD-2,MOD);Q=tot0*(tot0-1)/2+tot1*(tot1-1)/2;Q%=MOD;
	for (j=0;j<=tot0;j++){
		B[j][j]=(Q+j*(tot0-j)+(tot0-j)*(tot1-tot0+j)) % MOD*G % MOD;
		if (j>0) B[j-1][j]=(tot0-j+1)*(tot0-j+1) % MOD*G % MOD;
		if (j<tot0) B[j+1][j]=(j+1)*(tot1-tot0+j+1) % MOD*G % MOD;
	}
	A[0][rit]=1;
	for (;K;K>>=1,MulB()) if (K&1) MulA();
	/*for (now=1;now<=K;now++){
		for (i=0;i<=tot0;i++) //i:0;j:1 
		     {
			 j=tot0-i;
			 //f[now][i]=f[now-1][i]
			 //tot0*1
			 f[now][i]=(f[now][i]+f[now-1][i]*(Q+i*(tot0-i)+(tot0-i)*(tot1-tot0+i)) % MOD*G % MOD) % MOD;
			 if (i>0) f[now][i-1]=(f[now][i-1]+f[now-1][i]*i*(tot1-tot0+i) % MOD*G % MOD) % MOD;
			 //f[1][0][1]
			 //1 0
			 //f[2][1][0]=f[1][0][1]*
			 if (i<tot0) f[now][i+1]=(f[now][i+1]+f[now-1][i]*(tot0-i)*(tot0-i) % MOD*G % MOD) % MOD;
		     }
	}*/
	printf("%lld\n",A[0][tot0]);
    return 0;
}
//RemoteJudge ????? GGGGGGGGGGGGGGGG
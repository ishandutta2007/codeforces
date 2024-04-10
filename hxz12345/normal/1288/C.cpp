
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
long long pow(long long x,long long y,long long p)
{
	long long ans=1;
	for (;y;y>>=1,x=x*x % p)
		if (y&1) ans=ans*x % p;
	return ans;
}
long long gcd(long long x,long long y)
{
	if (y==0) return x;
	long long ans=gcd(y,x % y);return ans;
}
long long MOD,sum,ans,m,n,i,j,jt,j2,j3,j4,e[11][1003][1003],f[11][1003][1003];
long long x;
int main()
{
	n=read();m=read();MOD=1e9+7;
	//f[1][1]=2;f[1][2]=1
	//f[2][1]=3,f[2][2]=2;
	//f[3][1]=3,f[3][2]=4;
	//f[3][1]=4,f[3][2]=5;
   // for (i=1;i<=n;i++) f[1][i]=n-i+1;	
	for (i=1;i<=n;i++)
	   for (j=n;j>=i;j--) 
	       {
	       	x=e[1][i-1][j]+e[1][i][j+1]-e[1][i-1][j+1]+1;x=x% MOD;x=(x+MOD) % MOD;
	       e[1][i][j]=x;
		   f[1][i][j]=1;
	       }
	for (i=2;i<=m;i++)
	    {
	/*	for (jt=1;jt<=n;jt++)
		   for (j2=n;j2>=jt;j2--)
		      for (j3=1;j3<=jt;j3++)
		         for (j4=max(j3,j2);j4<=n;j4++)
		            f[i][jt][j2]+=f[i-1][j3][j4];*/
		/*2,1,2->1,2&1,3
		2,2,1->*/
	   for (jt=1;jt<=n;jt++)
	      {
	      	
	       for (j2=n;j2>=jt;j2--)
	           {
			   f[i][jt][j2]=e[i-1][jt][j2];
			   x=e[i][jt-1][j2]+e[i][jt][j2+1]-e[i][jt-1][j2+1]+f[i][jt][j2];x=(x % MOD+MOD) % MOD;
			   e[i][jt][j2]=x;
		       }
	      }
	}
	for (i=1;i<=n;i++)
	   for (j=i;j<=n;j++)
	       {
	      ans=(ans+f[m][i][j]) % MOD;
	      } 
    printf("%d\n",ans);
    return 0;
}
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
int j,a[2050][2050],pre1[2050][2050],pre2[2050][2050],suf1[2050][2050],suf2[2050][2050],x,y,n,i,b[100100],c[101000],sum;
int main()
{
	//ios::sync_with_stdio(0);cin.tie();cout.tie();
	n=read();
	for (i=1;i<=n;i++) 
	    {
	    	x=read();y=read();
	    	x+=1001;y+=1001;
		    a[x][y]=1;
		    b[i]=x;c[i]=y;
	     }
	for (i=1;i<=2001;i++)
	      {
	      	for (j=1;j<=2001;j++) pre1[i][j]=pre1[i][j-1]+a[i][j];
	      	for (j=2001;j>=0;j--) suf1[i][j]=suf1[i][j+1]+a[i][j];
		  }
	for (j=1;j<=2001;j++)
	      {
	      	for (i=1;i<=2001;i++) pre2[i][j]=pre2[i-1][j]+a[i][j];
	      	for (i=2001;i>=0;i--) suf2[i][j]=suf2[i+1][j]+a[i][j];
		  }
    for (i=1;i<=n;i++)
         {
         	x=b[i];y=c[i];
         	if ((pre1[x][y-1])&&(suf1[x][y+1])&&(pre2[x-1][y])&&(suf2[x+1][y]))     sum++;
		 }
	printf("%d\n",sum);
return 0;
}
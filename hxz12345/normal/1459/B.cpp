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
bool exist[2000][2000];
long long x,y,n,sum;
void sc(int x,int y,int z,int t)
{
	if (t==n)
	   {
	   	   if (exist[x+n][y+n]) return ;
	   	   exist[x+n][y+n]=true;sum++;
	   	   return;
	   }
	if (z==0)
	    {
	    	sc(x,y+1,1,t+1);sc(x,y-1,1,t+1);
	    	sc(x-1,y,2,t+1);sc(x+1,y,2,t+1);
		}
	if (z==1)
	    {
	    	sc(x-1,y,2,t+1);sc(x+1,y,2,t+1);
		}
	if (z==2)
	    {
	    	sc(x,y-1,1,t+1);sc(x,y+1,1,t+1);
		}
}
int main()
{
	n=read();
//	sc(0,0,0,0);
   if (n % 2==0) sum=(n/2+1)*(n/2+1);
   else
       {
       	x=n/2+1;
       	sum=2*x*(x+1);
	   }
	printf("%lld\n",sum);
   return 0;
}
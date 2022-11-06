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
long long L,R,w,h,T,W,H,lft,rit,up,down,x,y;
long long z;
double k;
int main()
{
	//ios::sync_with_stdio(0);cin.tie();cout.tie();
	for (T=read();T;T--)
	     {
	     	W=read();H=read();
	     	lft=read();down=read();rit=read();up=read();
	     	w=read();h=read();x=1e9;y=1e9;z=1e9;
	     	L=rit-lft;R=up-down;
	     	//(x,x+L) (y,y+R) 
	     	if ((lft>=w)) z=0;
	     	else if (rit+w-lft<=W) z=min(z,w-lft);
	     	if ((W-rit>=w)) z=0;
	     	else if (lft-(w-(W-rit))>=0) z=min(z,w-(W-rit)); 
	     	if ((down>=h)) z=0;
	     	else if (up+h-down<=H) z=min(z,h-down);
	     	if ((H-up>=h)) z=0;
	     	else if (down-(h-(H-up))>=0) z=min(z,h-(H-up));
			if ((z==1e9)) puts("-1");
			else 
			    {
			    	double k=z;
			    	printf("%.9lf\n",k);
				 } 
		 }
 return 0;
}
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
int n,t,K,sum;
int sc(int l,int r,int K)
{
	if (l==r) return l;
	int mid=(l+r)/2;
	cout<<"?"<<" "<<l<<" "<<mid<<endl;
	cin>>sum;
	int tot=mid-l+1-sum;
	cout.flush();
	if (tot<K) sc(mid+1,r,K-tot);
	else sc(l,mid,K);
}
//101101
int main()
{
	n=read();t=read();K=read();
	cout<<"!"<<" "<<sc(1,n,K)<<endl;
	cout.flush();
   return 0;
}
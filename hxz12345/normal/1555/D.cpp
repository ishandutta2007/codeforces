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
int l,r,T,n,m,i,ans,a[1010000],b[1010000],f[1010000][8];
string s;
int main()
{
	ios::sync_with_stdio(0);cin.tie();cout.tie();
	cin>>n>>m;
	cin>>s;
	for (i=1;i<=n;i++) a[i]=s[i-1]-'a'+1;
	for (i=1;i<=n;i++) 
	    {
	    	if (i % 3==1) b[i]=1;
	    	if (i % 3==2) b[i]=2;
	    	if (i % 3==0) b[i]=3;
		}
	for (i=1;i<=n;i++) f[i][1]=f[i-1][1]+(a[i]!=b[i]);
	for (i=1;i<=n;i++) 
	    {
	    	if (i % 3==1) b[i]=2;
	    	if (i % 3==2) b[i]=1;
	    	if (i % 3==0) b[i]=3;
		}
	for (i=1;i<=n;i++) f[i][2]=f[i-1][2]+(a[i]!=b[i]);
	for (i=1;i<=n;i++) 
	    {
	    	if (i % 3==1) b[i]=1;
	    	if (i % 3==2) b[i]=3;
	    	if (i % 3==0) b[i]=2;
		}
	for (i=1;i<=n;i++) f[i][3]=f[i-1][3]+(a[i]!=b[i]);
	for (i=1;i<=n;i++) 
	    {
	    	if (i % 3==1) b[i]=2;
	    	if (i % 3==2) b[i]=3;
	    	if (i % 3==0) b[i]=1;
		}
	for (i=1;i<=n;i++) f[i][4]=f[i-1][4]+(a[i]!=b[i]);
	for (i=1;i<=n;i++) 
	    {
	    	if (i % 3==1) b[i]=3;
	    	if (i % 3==2) b[i]=1;
	    	if (i % 3==0) b[i]=2;
		}
	for (i=1;i<=n;i++) f[i][5]=f[i-1][5]+(a[i]!=b[i]);
	for (i=1;i<=n;i++) 
	    {
	    	if (i % 3==1) b[i]=3;
	    	if (i % 3==2) b[i]=2;
	    	if (i % 3==0) b[i]=1;
		}
	for (i=1;i<=n;i++) f[i][6]=f[i-1][6]+(a[i]!=b[i]);
	for (;m;m--)
	    {
	    	cin>>l>>r;ans=n+1;
	    	for (i=1;i<=6;i++)
	    	   ans=min(ans,f[r][i]-f[l-1][i]);
	    	cout<<ans<<endl;
		}
 return 0;
}
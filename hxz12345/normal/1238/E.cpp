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
int now,nxt,j,val,final,e[101010],edge[310][310],fre[310],rel[2001010],f[2001010];
int n,m,i,sum;
string s;
int main()
{
	ios::sync_with_stdio(0);cin.tie();cout.tie();
    cin>>n>>m;
    cin>>s;sum=1e9;
    for (i=1;i<=n;i++)
         {
	     e[i]=s[i-1]-'a'+1;
	     if ((i-1>=1)&&(e[i]!=e[i-1])) edge[e[i]][e[i-1]]++,fre[e[i]]++;
	     }
	for (i=n-1;i>=1;i--)
	    if ((i+1<=n)&&(e[i]!=e[i+1])) edge[e[i]][e[i+1]]++,fre[e[i]]++;
	final=(1<<m)-1;
	for (i=1;i<=m;i++)
	     rel[1<<(i-1)]=i;
	for (i=0;i<=final;i++) f[i]=1e9;
	f[0]=0;
	for (now=0;now<final;now++)
	    for (i=1;i<=m;i++)
	        if ((now&(1<<(i-1)))==0)
	             {
	             	nxt=now|(1<<(i-1));sum=0;val=1;
	             	for (j=now;j;j-=(j&-j))
	             	    sum+=edge[i][rel[(j&-j)]],val++;
	             	//cout<<now<<" "<<nxt<<" "<<val<<" "<<sum<<" "<<fre[i]-sum<<" "<<f[now]<<endl;
	                f[nxt]=min(f[nxt],f[now]+(sum-(fre[i]-sum))*val);
				 }
	printf("%d\n",f[final]);
return 0;
}
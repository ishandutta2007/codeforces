#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int n,k,a[maxn],b[maxn],s1,s2;
const ll inf=1e9+7;

inline bool jud(int l,int r,int num,int x)
{
	int cnt=0,lst=-inf;
	for(int i=l;i<=r;i++)
	{
		if(a[i]<=x)
		{
			if(i-lst>=2) lst=i,cnt++;
		}
	}
	return cnt>=num;
}

inline bool jud1(int x)
{
	if(s1==s2) return jud(1,n-1,s1,x)||jud(2,n,s2,x);
	else return jud(1,n,s1,x)||jud(2,n-1,s2,x);
}

int main()
{
	n=read(); k=read(); rep(i,1,n) a[i]=read();
	s1=(k+1)/2; s2=k-s1;
	int l=1,r=inf,ans=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(jud1(mid)) r=mid-1,ans=mid;
		else l=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}
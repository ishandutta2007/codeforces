#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

long long ans;
int n,i,j,a[5005];
int gg[5005],p[2005],cnt,cc[2005],lst[5005];
int s[5005][2005],tmp[5005][2005],res[2005];
int alive[5005];

int main()
{
	for (i=2;i<=5000;i++)
	{
		if (gg[i])
		{
			continue;
		}
		p[++cnt]=i;
		s[i][cnt]=1;
		for (j=2;i*j<=5000;j++)
		{
			gg[i*j]=1;
			s[i*j][cnt]=s[j][cnt]+1;
		}
	}
//	cerr<<cnt<<endl;
	rep(i,5000)
	{
		rep(j,cnt) tmp[i][j]=(s[i][j]+=s[i-1][j]);
	}
	
	scanf("%d",&n);
	rep(i,n)
	{
		int x;
		scanf("%d",&x);
		if (x==0) x=1;
		a[x]++;
	}
	rep(i,5000)
	{
		if (i!=1) alive[i]=1;
		lst[i]=cnt;
	}
	
	while (1)
	{
		memset(cc,0,sizeof(cc));
		rep(i,5000) if (alive[i])
		{
			while (lst[i]>0&&!tmp[i][lst[i]]) lst[i]--;
			if (lst[i]==0) alive[i]=0; else cc[lst[i]]+=a[i];
		}
		int mx=0;
		rep(i,cnt) if (cc[i]>cc[mx]) mx=i;
		if (cc[mx]>n/2)
		{
			int mi=0x3fffffff;
			rep(i,5000) if (alive[i])
			{
				if (lst[i]==mx) mi=min(mi,tmp[i][mx]);  else alive[i]=0;
			}
			res[mx]+=mi;
			rep(i,5000) if (alive[i])
			{
				tmp[i][mx]-=mi;
			}
		}
		else break;
	}
	
	rep(i,5000)
	{
		per(j,cnt)
		{
			if (res[j]!=s[i][j]) break;
		}
		if (j==0) continue;
		ans+=1ll*a[i]*abs(res[j]-s[i][j]);
		for (j--;j>=0;j--) ans+=1ll*a[i]*(res[j]+s[i][j]);
	}
	
	cout<<ans<<endl;
	return 0;
}
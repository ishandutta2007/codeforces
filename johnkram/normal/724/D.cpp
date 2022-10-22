#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ll long long
set<pair<int,int> > S;
set<pair<int,int> >::iterator it;
char s[MAXN];
int n,m,i,j,k,l[MAXN],r[MAXN],a[MAXN];
int main()
{
	scanf("%d%s",&m,s+1);
	n=strlen(s+1);
	for(i=1;i<=n;i++)
	{
		l[i]=max(i-m+1,1);
		r[i]=min(i,n-m+1);
	}
	for(i='a';i<='z';i++)
	{
		for(j=1,k=0;j<=n;j++)if(s[j]==i)
		{
			k++;
			a[l[j]]++;
			a[r[j]+1]--;
		}
		for(j=1;j<=n-m+1;j++)a[j]+=a[j-1];
		for(j=1;j<=n-m+1;j++)if(!a[j])break;
		if(j<=n-m+1)
		{
			while(k--)putchar(i);
			for(j=n;j;j--)a[j]-=a[j-1];
			continue;
		}
		for(j=n-m+1;j;j--)a[j]-=a[j-1];
		for(j=1,k=0;j<=n;j++)if(s[j]==i)
		{
			S.insert(make_pair(l[j],r[j]));
			a[l[j]]--;
			a[r[j]+1]++;
		}
		for(j=1;j<=n-m+1;j++)a[j]+=a[j-1];
		for(j=1;j<=n-m+1;j++)if(!a[j])
		{
			it=S.lower_bound(make_pair(j+1,0));
			it--;
			putchar(i);
			j=it->second;
		}
		break;
	}
	return 0;
}
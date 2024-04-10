#include <bits/stdc++.h>
using namespace std;

int n,q,a[1000005],l,pre[1000005],suf[1000005];
long long s1[1000005],s2[1000005];
int qx[1000005],ql,qr;

void ins(int x)
{
	while(ql<=qr&&a[qx[qr]]<=a[x]) qr--;
	qx[++qr]=x;
}

void del(int x)
{
	while (ql<=qr&&qx[ql]<=x) ql++;
}

int main()
{
	int i,j;
	scanf("%d%d",&q,&n);
	
	while (q--)
	{
		scanf("%d",&l);
		for (i=1;i<=l;i++)
		{
			scanf("%d",&a[i]);
		}
		
		if (l*2<=n)
		{
			pre[0]=suf[l+1]=0;
			for (i=1;i<=l;i++)
			{
				pre[i]=max(pre[i-1],a[i]);
			}
			for (i=l;i>=1;i--)
			{
				suf[i]=max(suf[i+1],a[i]);
			}
			for (i=1;i<l;i++)
			{
				s1[i]+=pre[i];
				s1[n-i+1]+=suf[l-i+1];
			}
			s2[l]+=pre[l];
			s2[n-l+2]-=pre[l];
		}
		else
		{
			ql=1;qr=0;
			for (i=1;i<=n;i++)
			{
				if (i<=l) ins(i);
				if (i>(n-l+1)) del(i-(n-l+1));
				int s=a[qx[ql]];
				if (i>l||i+l<=n) s=max(s,0);
				s1[i]+=s; 
			}
		}
	}
	
	for (i=1;i<=n;i++) s2[i]+=s2[i-1];
	for (i=1;i<=n;i++) printf("%I64d ",s1[i]+s2[i]);
	
	return 0;
}
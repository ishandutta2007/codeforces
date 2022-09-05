#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
const int N=1e5+5,T=N*40;
int n,a[N],ap[N];
int cl[T],cr[T],s[T],tot=N;

#define mid ((l+r)/2)
void add(int k,int i,int w)
{
	int l=1,r=n,nk=k;
	while(1)
	{
		s[nk]=s[k]+w;
		if(l==r)break;
		if(i<=mid)
		{
			cr[nk]=cr[k];
			k=cl[k];
			nk=cl[nk]=++tot;
			r=mid;
		}
		else
		{
			cl[nk]=cl[k];
			k=cr[k];
			nk=cr[nk]=++tot;
			l=mid+1;
		}
	}
}
int find_mx(int x,int k)
{
	int l=1,r=n;
	while(l!=r)
	{
		if(k<s[cl[x]])
		{
			x=cl[x];
			r=mid;
		}
		else
		{
			k-=s[cl[x]];
			x=cr[x];
			l=mid+1;
		}
	}
	return l-(s[x]>k);
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif	
	cin>>n;
	rep(i,1,n)scanf("%d",a+i);
	per(i,n,1)
	{
		cl[i]=cl[i+1];
		cr[i]=cr[i+1];
		s[i]=s[i+1];
		if(ap[a[i]])add(i,ap[a[i]],-1);
		add(i,ap[a[i]]=i,1);
	}
	rep(k,1,n)
	{
		int ans=1,i=1;
		while(s[i]>k)
		{
			i=find_mx(i,k)+1;
			++ans;
		}
		printf("%d ",ans);
	}
}
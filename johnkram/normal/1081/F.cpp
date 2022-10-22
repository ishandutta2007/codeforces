#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ll long long
int n,m,i,j,k,l[10005],r[10005],ans[10005],a[10005];
void ask(int x,int y)
{
	cout<<"? "<<x<<' '<<y<<endl;
	fflush(stdout);
	cin>>ans[++m];
	if(((ans[m]^ans[m-1])&1)^(y&1))
	{
		l[m]=x;
		r[m]=n;
	}
	else
	{
		l[m]=1;
		r[m]=y;
	}
}
int main()
{
	cin>>n>>ans[0];
	if(n&1)if(n==1)a[1]=ans[0];
	else
	{
		for(i=1;i+1<n;i++)
		{
			for(;;)
			{
				ask(i+1,i+2);
				if(l[m]==i+1&&r[m]==n)break;
				else for(j=1;j<i;j++)a[j]=!a[j];
			}
			k=ans[m]-ans[m-1]+n-i>>1;
			for(j=1;j<i;j++)k+=a[j];
			a[i]=ans[m]-k;
		}
		for(;;)
		{
			ask(n-2,n-1);
			if(l[m]==1&&r[m]==n-1)
			{
				for(j=1;j+1<n;j++)a[j]=!a[j];
				break;
			}
			else a[n-2]=!a[n-2];
		}
		k=ans[m]-ans[m-1]+n-1>>1;
		a[n]=ans[m]-k;
		for(j=1;j+1<n;j++)k-=a[j];
		a[n-1]=k;
	}
	else
	{
		for(i=1;i<=n;i++)
		{
			for(;;)
			{
				ask(i,i);
				if(l[m]==1&&r[m]==i)break;
			}
			for(j=1,k=ans[m-1];j<i;j++)
			{
				if(a[j])k--;
				else k++;
				a[j]=!a[j];
			}
			if(k+1==ans[m])a[i]=1;
			else a[i]=0;
		}
	}
	for(i=1;i<=m;i++)for(j=l[i];j<=r[i];j++)a[j]=!a[j];
	cout<<"! ";
	for(i=1;i<=n;i++)cout<<a[i];
	fflush(stdout);
	return 0;
}
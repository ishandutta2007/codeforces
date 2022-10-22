#include<bits/stdc++.h>
using namespace std;
int n;
int ask(int x)
{
	cout<<"? "<<x<<endl;
	fflush(stdout);
	int s;
	cin>>s;
	if(!s)s=n+1;
	return s;
}
int ans,a[2005];
void work(int l,int r,int l1,int r1)
{
	if(l>r||l1>r1||l1*l>=ans)return;
	int mid=l+r>>1;
	int k=ask(mid),i;
	if(k<=n)ans=min(ans,k*mid);
	for(i=k;i<=n;i++)a[i]=min(a[i],mid);
	work(mid+1,r,l1,k-1);
	work(l,mid-1,k,r1);
}
int main()
{
	cin>>n;
	int N=n*2001-1,i;
	ans=N;
	for(i=1;i<=n;i++)a[i]=N;
	work(1,N-1,1,n);
	for(i=1;i<=n;i++)ans=min(ans,a[i]*i);
	cout<<"! "<<ans<<endl;
	fflush(stdout);
	return 0;
}
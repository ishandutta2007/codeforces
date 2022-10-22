#include<bits/stdc++.h>
using namespace std;
priority_queue<int> h;
int a[1005],n,m,i,j;
#define ll long long
ll ans;
int main()
{
	scanf("%d%d%d",&n,&m,&i);
	m+=i;
	for(i=0;i<n;i++)scanf("%d",a+i);
	for(i=0;i<n;i++)
	{
		scanf("%d",&j);
		a[i]=max(a[i]-j,j-a[i]);
	}
	for(i=0;i<n;i++)h.push(a[i]);
	for(;!h.empty()&&m;)
	{
		i=h.top();
		h.pop();
		if(i)
		{
			h.push(i-1);
			m--;
		}
	}
	if(h.empty())ans=m%2;
	else while(!h.empty())
	{
		i=h.top();
		h.pop();
		ans+=(ll)i*i;
	}
	cout<<ans<<endl;
	return 0;
}
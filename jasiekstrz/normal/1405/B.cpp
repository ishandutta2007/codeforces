#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
long long tab[100010];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q,n,i,x,y;
	long long ans=0,a,b;
	cin>>q;
	while(q--)
	{
		cin>>n;
		for(i=1;i<=n;i++)
			cin>>tab[i];
		ans=a=b=0;
		for(x=1,y=n;x<y;)
		{
			if(tab[x]>=0)
			{
				a+=tab[x];
				x++;
				continue;
			}
			else if(a>0)
			{
				long long t=min(a,-tab[x]);
				tab[x]+=t;
				a-=t;
				continue;
			}
			if(tab[y]<=0)
			{
				b-=tab[y];
				y--;
				continue;
			}
			else if(b>0)
			{
				long long t=min(b,tab[y]);
				tab[y]-=t;
				b-=t;
				continue;
			}
			long long xd=min(-tab[x],tab[y]);
			tab[x]+=xd;
			tab[y]-=xd;
			ans+=xd;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
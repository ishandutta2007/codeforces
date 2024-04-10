#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q,n,m,k,hp,h,i,qi;
	bool czy;
	cin>>q;
	for(qi=1;qi<=q;qi++)
	{
		cin>>n>>m>>k;
		czy=true;
		cin>>hp;
		for(i=2;i<=n;i++)
		{
			cin>>h;
			if(h>hp)
			{
				m-=max(h-k-hp,-hp);
				if(m<0)
					czy=false;
			}
			else
			{
				m+=min(hp+k-h,hp);
			}
			hp=h;
		}
		if(czy==true)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}
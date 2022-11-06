#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    ll d[n],p1=0,p3=n-1;
    for(int i=0;i<n;i++)
    {
    	cin>>d[i];
	}
	ll sum1=0,sum2=0,ans;
	for (int i=0;i<n;i++)
	{
		if (sum1==sum2)
		{
			ans=sum1;
			sum1+=d[p1];
			p1+=1;
		}
		else if(sum1>sum2)
		{
			sum2+=d[p3];
			p3-=1;
		}
		else
		{
			sum1+=d[p1];
			p1+=1;
		}
	}
	if(sum1==sum2)
	ans=sum1;
	cout<<ans;
	return 0;
}
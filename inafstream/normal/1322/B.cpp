#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

int n,i,ans;
vector<int> v,v0,v1;

int main()
{
	scanf("%d",&n);
	rep(i,n)
	{
		int x;
		scanf("%d",&x);
//		ans^=(x+x);
		v.push_back(x);
	}
	
	int msk=0;
	for (i=0;i<=28;i++)
	{
		int j,k,s=0;
		for (j=0;j<v.size();j++)
		{
			if ((v[j]>>i)&1) v1.push_back(v[j]); else v0.push_back(v[j]);
		}
		
		k=v1.size()-1;
		for (j=0;j<v0.size();j++)
		{
			while (k>=0&&(v0[j]&msk)+(v1[k]&msk)>msk)
			{
				k--;
			}
			if ((k+1)&1) s^=1;
		}
		
		k=v0.size()-1;
		for (j=0;j<v0.size();j++)
		{
			while (k>=0&&(v0[j]&msk)+(v0[k]&msk)>msk)
			{
				k--;
			}
			if ((v0.size()-1-max(j,k))&1) s^=1;
		}
		
		k=v1.size()-1;
		for (j=0;j<v1.size();j++)
		{
			while (k>=0&&(v1[j]&msk)+(v1[k]&msk)>msk)
			{
				k--;
			}
			if ((v1.size()-1-max(j,k))&1) s^=1;
		}
		
		if (s) ans^=(1<<i);

		msk=((msk<<1)|1);
		v.clear();
		for (j=0;j<v0.size();j++) v.push_back(v0[j]);
		for (j=0;j<v1.size();j++) v.push_back(v1[j]);
		v0.clear();v1.clear();
	}
	
	cout<<ans<<endl;
	return 0;
}
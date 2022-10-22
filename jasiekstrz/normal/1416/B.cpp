#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
struct Q
{
	int a,b,c;
};
int tab[10010];
set<pair<int,int>> mxfree,mngap;
vector<Q> ans;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q,n,i;
	int sum,x;
	cin>>q;
	while(q--)
	{
		cin>>n;
		sum=0;
		mxfree.clear();
		mngap.clear();
		ans.clear();
		for(i=1;i<=n;i++)
		{
			cin>>tab[i];
			sum+=tab[i];
			if(i==1)
				continue;
			if(tab[i]>=i)
				mxfree.insert({-(tab[i]-(tab[i]%i)),i});
			if(tab[i]%i>0)
				mngap.insert({(i-(tab[i]%i))%i,i});
		}
		x=sum/n;
		if(sum%n!=0)
		{
			cout<<"-1\n";
			continue;
		}
		while(!mngap.empty())
		{
			int xd=(mngap.begin()->se);
			mngap.erase(mngap.begin());
			while((tab[1]<(xd-(tab[xd]%xd))%xd)&&(!mxfree.empty()))
			{
				int tmp=(mxfree.begin()->se);
				tab[1]-=(mxfree.begin()->fi);
				mxfree.erase(mxfree.begin());
				ans.push_back({tmp,1,tab[tmp]/tmp});
				tab[tmp]%=tmp;
			}
			if(tab[1]<(xd-(tab[xd]%xd))%xd)
			{
				if(tab[xd]%xd==x%xd)
					continue;
				cout<<"-1\n";
				goto bad;
			}
			if(mxfree.find({-(tab[xd]-(tab[xd]%xd)),xd})!=mxfree.end())
				mxfree.erase({-(tab[xd]-(tab[xd]%xd)),xd});
			ans.push_back({1,xd,(xd-(tab[xd]%xd))%xd});
			tab[1]-=(xd-(tab[xd]%xd))%xd;
			tab[xd]+=(xd-(tab[xd]%xd))%xd;
			tab[1]+=tab[xd];
			ans.push_back({xd,1,tab[xd]/xd});
			tab[xd]=0;
		}
		while(!mxfree.empty())
		{
			int tmp=(mxfree.begin()->se);
			tab[1]-=(mxfree.begin()->fi);
			mxfree.erase(mxfree.begin());
			ans.push_back({tmp,1,tab[tmp]/tmp});
			tab[tmp]%=tmp;
		}
		for(i=2;i<=n;i++)
		{
			if(tab[i]!=x)
			{
				ans.push_back({1,i,x-tab[i]});
			}
		}
		if(ans.size()>3*n)
			cout<<"-1\n";
		else
		{
			cout<<ans.size()<<"\n";
			for(auto v:ans)
				cout<<v.a<<" "<<v.b<<" "<<v.c<<"\n";
		}
		bad:;
	}
	return 0;
}
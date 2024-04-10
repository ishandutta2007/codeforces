#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int p[1000010];
int l[1000010];
int k[1000010];
bool vis[1000010];
vector<int> ans[2];
inline int nt(int x,int n)
{
	return (x<=n ? x+n:x-n);
}
int main()
{
	int n;
	cin>>n;
	if(n%2==0)
	{
		cout<<"First"<<endl;
		for(int i=1;i<=n;i++)
			cout<<i<<" ";
		for(int i=1;i<=n;i++)
			cout<<i<<" ";
		cout<<endl;
		cin>>n;
		return 0;
	}
	cout<<"Second"<<endl;
	for(int i=1;i<=2*n;i++)
	{
		cin>>p[i];
		if(l[p[i]]==0)
			l[p[i]]=i;
		else
		{
			k[i]=l[p[i]];
			k[l[p[i]]]=i;
		}
	}
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;!vis[j];)
		{
			ans[0].push_back(j);
			ans[1].push_back(k[j]);
			sum+=j;
			vis[j]=vis[k[j]]=true;
			j=nt(k[j],n);
		}
	}
	if(sum%2==0)
	{
		for(auto v:ans[0])
			cout<<v<<" ";
	}
	else
	{
		for(auto v:ans[1])
			cout<<v<<" ";
	}
	cout<<endl;
	cin>>n;
	return 0;
}
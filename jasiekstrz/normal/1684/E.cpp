#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N=2e5;
map<int,int> mp;
map<int,int> mn;
vector<pair<int,int>> srt;
void pushsrt(int &lft)
{
	while(!srt.empty())
	{
		auto [b,a]=srt.back();
		if(mp.find(a)==mp.end())
		{
			srt.pop_back();
			continue;
		}
		if(b>lft)
			return;
		lft-=b;
		mn[a]=b;
		srt.pop_back();
	}
	return;
}
int solve()
{
	int n,k;
	cin>>n>>k;
	mp.clear();
	srt.clear();
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		mp[x]++;
	}
	for(auto [a,b]:mp)
		srt.emplace_back(b,a);
	sort(srt.begin(),srt.end());
	reverse(srt.begin(),srt.end());
	mn.clear();
	int miss=0;
	int lft=k;
	pushsrt(lft);
	int ans=mp.size();
	for(int mex=0;mex<=n;mex++)
	{
		if(miss>k)
			break;
		if(mp.find(mex)==mp.end())
		{
			ans=min(ans,(int)mp.size()-(int)mn.size());
			miss++;
		}
		else
		{
			mp.erase(mex);
			if(mn.find(mex)!=mn.end())
			{
				lft+=mn[mex];
				mn.erase(mex);
				pushsrt(lft);
			}
		}
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	cin>>q;
	while(q--)
		cout<<solve()<<"\n";
	return 0;
}
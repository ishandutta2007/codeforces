#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
set<int> b;
vector<int> w;
bool ok(int n,vector<int> tab)
{
	b.clear();
	b={0};
	w.clear();
	for(auto v:tab)
	{
		if(b.find(v)!=b.end())
			continue;
		w.push_back(v);
		vector<int> tmp;
		for(auto c:b)
			tmp.push_back(c^v);
		for(auto c:tmp)
			b.insert(c);
	}
	return (b.size()==n);
}
void solve(int z,int p,bool r)
{
	if(p==1)
	{
		cout<<(z^(r*w[p-1]))<<" "<<(z^((!r)*w[p-1]))<<" ";
		return;
	}
	solve(z^(r*w[p-1]),p-1,0);
	solve(z^((!r)*w[p-1]),p-1,1);
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	vector<int> tab(n);
	for(int i=0;i<n;i++)
		cin>>tab[i];
	sort(tab.begin(),tab.end());
	for(int i=18;i>=1;i--)
	{
		while(!tab.empty() && tab.back()>=(1<<i))
			tab.pop_back();
		if(ok((1<<i),tab))
		{
			cout<<i<<"\n";
			solve(0,i,0);
			cout<<"\n";
			return 0;
		}
	}
	cout<<"0\n0\n";
	return 0;
}
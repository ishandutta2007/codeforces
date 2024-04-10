#include <bits/stdc++.h>

using namespace std;
int a[1001], b[1001];
int n, m;
vector <pair<int, char> > sol;
int solve(int left, int right, int ant)
{
	int vmax=a[left];
	if(right-left == 1)
		return 1;
	int ok=0;
	for(int i=left+1;i<right;i++)
	{
		vmax=max(vmax, a[i]);
		if(a[i] != a[i-1])
			ok=1;
	}
	if(ok==0)
		return 0;
	int cand=-1;
	char x;
	if(vmax == a[left] && a[left+1] != vmax)
	{
		cand = left;
		for(int i=left;i<right-1;i++)
		{
			sol.push_back({ant,'R'});
		}
	}
	else
		if(vmax == a[right-1] && a[right-2] != vmax)
		{
			cand = right-1;
			for(int i=left+1;i<right;i++)
			{
				sol.push_back({cand-left+ant, 'L'});
				cand--;
			}

		}
	else
	{
		for(int i=left+1;i<right-1;i++)
		{
			if(a[i] == vmax && a[i-1] < vmax)
			{
				cand=i;
				x='L';
				break;
			}
			if(a[i] == vmax && a[i+1] < vmax)
			{

				cand=i;
				x='R';
				break;
			}
		}
		int cand2=cand;
		if(x=='L')
		{
			for(int i=1;i<=cand-left;i++)
			{
				sol.push_back({cand2-left+ant, 'L'});
				cand2--;
			}

			for(int i=cand;i<right-1;i++)
			{
				sol.push_back({cand2-left+ant, 'R'});
			}
		}
		else
		{
			for(int i=cand;i<right-1;i++)
			{
				sol.push_back({cand2-left+ant, 'R'});
			}

			for(int i=1;i<=cand-left;i++)
			{
				sol.push_back({cand2-left+ant, 'L'});
				cand2--;
			}

		}

	}


	return 1;
}

int main(int argc, char const *argv[])
{
//	freopen("in.txt", "r", stdin);

	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];

	cin>>m;
	for(int i=1;i<=m;i++)
		cin>>b[i];

	int index=1;
	for(int i=1;i<=m;i++)
	{
		int sum=0;
		int left=index;
		while(sum<b[i] && index<=n)
			sum+=a[index++];

		if(sum!=b[i])
		{
			cout<<"NO\n";
			return 0;
		}

		bool ok=solve(left, index, i);
		if(!ok)
		{
			cout<<"NO\n";
			return 0;
		}
	}
	if(index <= n)
		{
			cout<<"NO\n";
			return 0;
		}

	cout<<"YES\n";

	for(int i=0;i<sol.size();i++)
		cout<<sol[i].first << ' '<< sol[i].second<<'\n';

	return 0;
}
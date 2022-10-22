#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int wczyt[300010];
int co[300010];
vector<int> s[300010];
int przed[300010];
int po[300010];
bool wywalone[300010];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m,a,b,w,i,j,k;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>wczyt[i];
		co[wczyt[i]]=i;
		przed[i]=i-1;
		po[i]=i+1;
	}
	for(i=1;i<=m;i++)
	{
		cin>>a>>b;
		s[co[a]].push_back(co[b]);
	}
	w=0;
	for(i=n-1;i>=1;i--)
	{
		if(s[i].empty())
			continue;
		sort(s[i].begin(),s[i].end());
		j=0;
		while(((unsigned)j<s[i].size()-1)&&((s[i][j]<=i)||(wywalone[s[i][j]])))
			j++;
		if((s[i][j]!=po[i])||(s[i][s[i].size()-1]!=n))
			continue;
		for(;(unsigned)j<s[i].size()-1;j++)
		{
			k=j+1;
			while(((unsigned)k<s[i].size()-1)&&(wywalone[s[i][k]]))
				k++;
			if(s[i][k]!=po[s[i][j]])
				goto xd;
			j=k-1;
		}
		//cout<<i<<"\n";
		w++;
		po[przed[i]]=po[i];
		przed[po[i]]=przed[i];
		wywalone[i]=true;
		xd:;
	}
	cout<<w;
	return 0;
}
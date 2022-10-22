#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
int tab[300010];
vector<int> vec;
vector<int> kra[2];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,a,w,i,j,k;
	bitset<35> b;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>tab[i];
	}
	vec.pb(0);
	kra[0].pb(0);
	kra[1].pb(0);
	for(i=1;i<=n;i++)
	{
		cin>>a;
		b=a;
		k=0;
		for(j=30;j>=0;j--)
		{
			if(kra[b[j]][k]==0)
			{
				kra[b[j]][k]=vec.size();
				vec.pb(0);
				kra[0].pb(0);
				kra[1].pb(0);
			}
			k=kra[b[j]][k];
			vec[k]++;
		}
	}
	for(i=1;i<=n;i++)
	{
		w=0;
		b=tab[i];
		k=0;
		for(j=30;j>=0;j--)
		{
			if(vec[kra[b[j]][k]]>0)
				k=kra[b[j]][k];
			else
			{
				k=kra[!b[j]][k];
				w+=(1<<j);
			}
			vec[k]--;
		}
		cout<<w<<" ";
	}
	return 0;
}
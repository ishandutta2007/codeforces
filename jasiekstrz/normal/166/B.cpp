#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
pair<pair<int,int>,bool> tab[200010];
vector<int> stos;
inline long long ilo(pair<int,int> x,pair<int,int> y,pair<int,int> z)
{
	long long x1,x2,y1,y2;
	x1=y.fi-x.fi;
	y1=y.se-x.se;
	x2=z.fi-y.fi;
	y2=z.se-y.se;
	return x1*y2-x2*y1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m,i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>tab[i].fi.fi>>tab[i].fi.se;
		tab[i].se=false;
	}
	cin>>m;
	for(i=n+1;i<=n+m;i++)
	{
		cin>>tab[i].fi.fi>>tab[i].fi.se;
		tab[i].se=true;
	}
	sort(tab+1,tab+n+m+1);
	for(i=1;i<=n+m;i++)
	{
		while((stos.size()>=2)&&(ilo(tab[stos[stos.size()-2]].fi,tab[stos.back()].fi,tab[i].fi)>0))
			stos.pop_back();
		stos.push_back(i);
	}
	for(i=n+m-1;i>=1;i--)
	{
		while((stos.size()>=2)&&(ilo(tab[stos[stos.size()-2]].fi,tab[stos.back()].fi,tab[i].fi)>0))
			stos.pop_back();
		stos.push_back(i);
	}
	while(!stos.empty())
	{
		if(tab[stos.back()].se)
		{
			//cerr<<stos.back()<<" "<<tab[stos.back()].fi.fi<<" "<<tab[stos.back()].fi.se<<"\n";
			cout<<"NO\n";
			return 0;
		}
		stos.pop_back();
	}
	cout<<"YES\n";
	return 0;
}
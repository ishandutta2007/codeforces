#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=551;
ll cnt,kk,ccnt,res;
inline ll read()
{
    register ll num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-')
    {
        ch=getchar();
    }
    if(ch=='-')
    {
        neg=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        num=(num<<3)+(num<<1)+(ch-'0');
        ch=getchar();
    }
    return num*neg;
}
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(nullptr);
	cin>>kk,cnt=1<<kk;
	vector<vector<ll> >x(cnt,vector<ll>(cnt));
	for(register int i=0;i<cnt;i++)
	{
		for(register int j=0;j<cnt;j++)
		{
			cin>>x[i][j];
		}
	}
	cin>>ccnt;
	vector<pair<ll,ll> >f(ccnt);
	for(register int i=0;i<ccnt;i++)
	{
		cin>>f[i].first>>f[i].second;
	}
	for(register int i=ccnt-1;i>=0;i--)
	{
		f[i].first=f[i].first-f[0].first;
		f[i].second=f[i].second-f[0].second;
	}
	for(register int i=0;i<kk;i++)
	{
		vector<vector<ll> >v(cnt,vector<ll>(cnt));
		for(register int j=0;j<cnt;j++)
		{
			for(register int k=0;k<cnt;k++)
			{
				for(register int l=0;l<ccnt;l++)
				{
					v[j][k]^=x[(j-f[l].first+cnt)&(cnt-1)][(k-f[l].second+cnt)&(cnt-1)];
				}
			}
		}
		x=v;
		for(register int j=0;j<ccnt;j++)
		{
			f[j].first=(f[j].first<<1)&(cnt-1);
			f[j].second=(f[j].second<<1)&(cnt-1);
		}
	}
	for(register int i=0;i<cnt;i++)
	{
		for(register int j=0;j<cnt;j++)
		{
			res+=(bool)x[i][j];
		}
	}
	cout<<res<<endl;
}
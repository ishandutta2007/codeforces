#include<bits/stdc++.h>
using namespace std;
vector<int> v[1000005];
bool czy_jest[1000005];
long long dp[1000005];
int tab[1000005];
int mod=1e9+7;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    cin>>a;
    for(int x=0;x<a;x++)
    {
        cin>>tab[x];
        czy_jest[tab[x]]=true;
    }
    for(int x=1;x<=1e3;x++)
    {
        for(int y=x;y<=1e6;y+=x)
        {
            if(x>y/x)
                continue;
            if(czy_jest[y]==true)
            {
                v[y].push_back(x);
                if(x*x!=y)
                    v[y].push_back(y/x);
            }
        }
    }
    for(int x=1;x<=1e6;x++)
        sort(v[x].begin(),v[x].end());
    for(int x=0;x<a;x++)
    {
        for(int y=v[tab[x]].size()-1;y>0;y--)
        {
            dp[v[tab[x]][y]]+=dp[v[tab[x]][y]-1];
            dp[v[tab[x]][y]]%=mod;
        }
        dp[1]++;
    }
    long long licz=0;
    for(int x=1;x<=1e6;x++)
        licz+=dp[x];
    cout<<licz%mod;

	return 0;
}
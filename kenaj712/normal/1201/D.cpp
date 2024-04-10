#include<bits/stdc++.h>
using namespace std;
vector<long long> v;
vector<int> poz[1000005];
vector<pair<long long,long long>> dp;
vector<pair<long long,long long>> dp2;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d;
    while(c--)
    {
        cin>>e>>f;
        poz[e].push_back(f);
    }
    for(int x=1;x<=a;x++)
        sort(poz[x].begin(),poz[x].end());
    while(d--)
    {
        cin>>e;
        v.push_back(e);
    }
    v.push_back(-1e12);
    v.push_back(1e12);
    sort(v.begin(),v.end());
    if(poz[1].empty()==true)
        dp.push_back(make_pair(1,0));
    else
        dp.push_back(make_pair(poz[1].back(),poz[1].back()-1));
    long long pom1,pom2,pom3,pom4,pom5,mini1,mini2,mini,japierdole=1;
    for(int x=2;x<=a;x++)
    {
        if(poz[x].size()==0)
            continue;
        else if(poz[x].size()==1)
        {
            japierdole=x;
            pom1=poz[x][0];
            pom2=dp[0].first;
            pom3=dp[0].second;
            pom4=lower_bound(v.begin(),v.end(),pom2)-v.begin();
            mini=1e18;
            mini=min(mini,abs(v[pom4]-pom1)+abs(v[pom4]-pom2));
            pom4--;
            mini=min(mini,abs(v[pom4]-pom1)+abs(v[pom4]-pom2));
            mini1=mini+pom3;
            mini2=1e18;
            if(dp.size()==2)
            {
                pom2=dp[1].first;
                pom3=dp[1].second;
                pom4=lower_bound(v.begin(),v.end(),pom2)-v.begin();
                mini=1e18;
                mini=min(mini,abs(v[pom4]-pom1)+abs(v[pom4]-pom2));
                pom4--;
                mini=min(mini,abs(v[pom4]-pom1)+abs(v[pom4]-pom2));
                mini2=mini+pom3;
            }

            dp2.push_back(make_pair(pom1,min(mini1,mini2)));
            dp=dp2;
            dp2.resize(0);
        }
        else
        {
            japierdole=x;
            mini2=1e18;
            pom1=poz[x][0];
            pom2=dp[0].first;
            pom3=dp[0].second;
            pom4=lower_bound(v.begin(),v.end(),pom2)-v.begin();
            mini=1e18;
            mini=min(mini,abs(v[pom4]-pom1)+abs(v[pom4]-pom2));
            pom4--;
            mini=min(mini,abs(v[pom4]-pom1)+abs(v[pom4]-pom2));
            mini1=mini+pom3;
            if(dp.size()==2)
            {
                pom2=dp[1].first;
                pom3=dp[1].second;
                pom4=lower_bound(v.begin(),v.end(),pom2)-v.begin();
                mini=1e18;
                mini=min(mini,abs(v[pom4]-pom1)+abs(v[pom4]-pom2));
                pom4--;
                mini=min(mini,abs(v[pom4]-pom1)+abs(v[pom4]-pom2));
                mini2=mini+pom3;
            }
            dp2.push_back(make_pair(poz[x].back(),min(mini1,mini2)+poz[x].back()-pom1));

            mini2=1e18;
            pom1=poz[x].back();
            pom2=dp[0].first;
            pom3=dp[0].second;
            pom4=lower_bound(v.begin(),v.end(),pom2)-v.begin();
            mini=1e18;
            mini=min(mini,abs(v[pom4]-pom1)+abs(v[pom4]-pom2));
            pom4--;
            mini=min(mini,abs(v[pom4]-pom1)+abs(v[pom4]-pom2));
            mini1=mini+pom3;
            if(dp.size()==2)
            {
                pom2=dp[1].first;
                pom3=dp[1].second;
                pom4=lower_bound(v.begin(),v.end(),pom2)-v.begin();
                mini=1e18;
                mini=min(mini,abs(v[pom4]-pom1)+abs(v[pom4]-pom2));
                pom4--;
                mini=min(mini,abs(v[pom4]-pom1)+abs(v[pom4]-pom2));
                mini2=mini+pom3;
            }
            dp2.push_back(make_pair(poz[x][0],min(mini1,mini2)+poz[x].back()-poz[x][0]));
            dp=dp2;
            dp2.resize(0);
        }
    }
    if(dp.size()==1)
        cout<<dp[0].second+japierdole-1;
    else
        cout<<min(dp[0].second,dp[1].second)+japierdole-1;
	return 0;
}
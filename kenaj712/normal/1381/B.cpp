#include<bits/stdc++.h>
using namespace std;
vector<int> v;
bool dp[8005];
void solve()
{
    int a;
    cin>>a;
    int licz=0,maks=0;
    for(int x=0;x<2*a;x++)
    {
        int b;
        cin>>b;
        if(b>maks)
        {
            maks=b;
            if(licz!=0)
            {
                v.push_back(licz);
                licz=0;
            }
        }
        licz++;
    }
    v.push_back(licz);
    dp[0]=true;
    for(auto x:v)
        for(int y=2*a;y>=0;y--)
            if(dp[y])
                dp[y+x]=true;
    if(dp[a])
        cout<<"YES";
    else
        cout<<"NO";
    cout<<'\n';
    for(int x=0;x<=2*a;x++)
        dp[x]=false;
    v.resize(0);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
	return 0;
}
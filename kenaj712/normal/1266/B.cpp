#include<bits/stdc++.h>
using namespace std;
bool dp[2005];
vector<int> v;
vector<int> v2;
void pre()
{
    for(int x=1;x<=6;x++)
        v2.push_back(21-x);
}
void solve()
{
    long long a;
    cin>>a;
    long long xd=14;
    if(a>=14)
    {
        a%=xd;
        a+=14;
    }

    for(auto x:v2)
        if(a-x==0)
    {
        cout<<"YES"<<'\n';
        return ;
    }
    cout<<"NO"<<'\n';
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	pre();
    int t;
    cin>>t;
    while(t--)
        solve();
	return 0;
}
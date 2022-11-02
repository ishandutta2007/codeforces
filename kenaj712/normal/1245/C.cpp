#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long dp[1000005];
void pre()
{
    dp[1]=1;
    dp[2]=2;
    for(int x=3;x<=1e5+5;x++)
        dp[x]=(dp[x-1]+dp[x-2])%mod;
}
vector<long long> v;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    pre();
    string a;
    cin>>a;
    long long ans=1,licz=0;
    char last='?';
    for(int x=0;x<a.size();x++)
    {
        if(a[x]=='w'||a[x]=='m')
        {
            cout<<0;
            return 0;
        }
        else if(a[x]=='u')
        {
            if(last=='u')
                licz++;
            else
            {
                if(last=='n')
                    v.push_back(licz);
                licz=1;
            }
        }
        else if(a[x]=='n')
        {
            if(last=='n')
                licz++;
            else
            {
                if(last=='u')
                    v.push_back(licz);
                licz=1;
            }
        }
        else if(last=='u'||last=='n')
        {
            v.push_back(licz);
        }
        last=a[x];
    }
    if(last=='u'||last=='n')
        v.push_back(licz);
    for(auto x:v)
        ans=(ans*dp[x])%mod;
    cout<<ans;
	return 0;
}
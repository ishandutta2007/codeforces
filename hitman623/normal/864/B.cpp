#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{
    io
    map<char,long>mp;
    long n,i,c=0,ans=0;
    string s;
    cin>>n>>s;
    for(i=0;i<n;++i)
    {
        if(isupper(s[i]))
        {c=0;mp.clear();}
        else
        {
            if(mp[s[i]]==0)
            c++;
            mp[s[i]]=1;
        }
        ans=max(ans,c);
    }
    cout<<ans;
    return 0;
}
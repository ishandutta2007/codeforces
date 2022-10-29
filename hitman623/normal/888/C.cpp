#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define vl vector < long >
#define pll pair < long , long >
#define vll vector < pll >
#define x first
#define y second
#define ml map < long , long >
#define mll map < pll , long >
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    io
    long n,i,j,ans=1e9;
    string s;
    cin>>s;
    n=s.length();
    for(i=0;i<26;++i)
    {
        long c=0,cur=0;
        for(j=0;j<n;++j)
        if(s[j]=='a'+i)
        {
            cur=max(cur,c+1);
            c=0;
        }
        else c++;
        cur=max(cur,c+1);
        ans=min(ans,cur);
    }
    cout<<ans;
    return 0;
}
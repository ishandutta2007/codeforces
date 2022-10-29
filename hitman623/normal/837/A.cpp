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
    long n,i,c=0,ans=0;
    string s;
    cin>>n;
    while(cin>>s)
    {
        for(i=0;i<s.length();++i)
        if(isupper(s[i])) c++;
        ans=max(ans,c);
        c=0;
    }
    cout<<ans;
    return 0;
}
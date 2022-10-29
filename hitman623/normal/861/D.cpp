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
    string s[70007];
    unordered_map < long , long > mp;
    long n,i,j,k;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>s[i];
        for(j=0;j<9;++j)
        {
            long ss=0,cur=31;
            for(k=j;k<9;++k)
            {
                ss+=(s[i][k]-'0'+1)*cur;
                cur=cur*23;
                mp[ss]++;
            }
        }
    }
    for(i=0;i<n;++i)
    {
        for(j=0;j<9;++j)
        {
            long ss=0,cur=31;
            for(k=j;k<9;++k)
            {
                ss+=(s[i][k]-'0'+1)*cur;
                cur=cur*23;
                mp[ss]--;
            }
        }
        string ans="12345678900";
        for(j=0;j<9;++j)
        {
            long ss=0,cur=31;
            string w;
            for(k=j;k<9;++k)
            {
                ss+=(s[i][k]-'0'+1)*cur;
                w+=s[i][k];
                cur=cur*23;
                if(mp[ss]==0)
                if(w.length()<ans.length())
                ans=w;
            }
        }
        cout<<ans<<"\n";
        for(j=0;j<9;++j)
        {
            long ss=0,cur=31;
            for(k=j;k<9;++k)
            {
                ss+=(s[i][k]-'0'+1)*cur;
                cur=cur*23;
                mp[ss]++;
            }
        }
    }
    return 0;
}
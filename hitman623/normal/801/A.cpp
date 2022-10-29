#include <bits/stdc++.h>
#define pb push_back
using namespace std;

long cnt(string s)
{
    long c=0,i;
    for(i=0;i<s.size()-1;++i)
    if(s[i+1]=='K' && s[i]=='V') c++;
    return c;
}
int main()
{
    string s;
    long i,ans=0;
    cin>>s;
    ans=cnt(s);
    for(i=0;i<s.size();++i)
    {
        if(s[i]=='V')
        {
            s[i]='K';
            ans=max(ans,cnt(s));
            s[i]='V';
        }
        else
        {
            s[i]='V';
            ans=max(ans,cnt(s));
            s[i]='K';
        }
    }
    cout<<ans;
    return 0;
}
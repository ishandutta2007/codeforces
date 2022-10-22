#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    ll t,cur,mn;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        ll ans=s.size();
        cur=0,mn=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='+')cur++;
            else cur--;
            if(cur<0&&cur<mn){ans+=(i+1)*(mn-cur);mn=cur;}
        }
        cout<<ans<<endl;
    }
    return 0;
}
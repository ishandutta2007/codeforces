#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    int q;
    cin>>q;
    while(q--)
    {
        string s,t;
        cin>>s>>t;
    int j=0;
    bool bl=false;
    for(int i=0;i<t.size();i++)
    {
       for(int j=0;j<s.size();j++)if(s[i]==t[j]){bl=true;break;}
       if(bl)break;
    }
    if(bl)cout<<"YES\n";
    else cout<<"NO\n";
    }
    return 0;
}
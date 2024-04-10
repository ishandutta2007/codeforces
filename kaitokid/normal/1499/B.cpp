#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    string s;
    cin>>s;
    bool a=false,b=false;
    for(int i=1;i<s.size();i++)
    {
        if(s[i]=='1'&&s[i-1]=='1'){a=true;continue;}
        if(a&&s[i]=='0'&&s[i-1]=='0'){b=true;break;}
    }
    if(b)cout<<"NO\n";
    else cout<<"YES\n";
    }
    return 0;
}
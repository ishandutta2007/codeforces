#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string,bool>mp;
string s[100009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {mp.clear();
    int n;
    cin>>n;
    bool ans=false;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        if(s[i].size()==1)ans=true;
        int r=s[i].size();
        r--;
        if(s[i][0]==s[i][r])ans=true;
    }
    if(ans){cout<<"YES"<<endl;continue;}
    for(int i=0;i<n;i++)
    {
        mp[s[i]]=true;
        string d=s[i];
        reverse(d.begin(),d.end());
        if(mp[d]){ans=true;break;}
        d.pop_back();
        if(mp[d]){ans=true;break;}
    }
    mp.clear();
    for(int i=n-1;i>=0;i--)
    {
        mp[s[i]]=true;
        string d=s[i];
        d.pop_back();
        reverse(d.begin(),d.end());
        if(mp[d]){ans=true;break;}
    }
    if(ans)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;


    }
    return 0;
}
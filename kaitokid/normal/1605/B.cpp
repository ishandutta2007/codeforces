#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        int n;
        string s;
        cin>>n>>s;
        int fr[2]={0,0};
        for(int i=0;i<n;i++)
            fr[s[i]-'0']++;
            vector<int>v;
        for(int i=0;i<fr[0];i++)
            if(s[i]=='1')v.push_back(i+1);
        for(int i=fr[0];i<n;i++)
            if(s[i]=='0')v.push_back(i+1);
        if(v.empty())
        {cout<<0<<endl;continue;}
        cout<<1<<endl;
        cout<<v.size()<<" ";
        for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
        cout<<endl;
    }
    return 0;
}
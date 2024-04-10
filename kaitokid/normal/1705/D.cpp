#include<bits/stdc++.h>
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
        ll n;
        string s,v;
        cin>>n>>s>>v;
        if(s[0]!=v[0]){cout<<-1<<endl;continue;}
        vector<ll>a,b;
        for(int i=0;i+1<n;i++)
        {
            if(s[i]!=s[i+1])a.push_back(i);
            if(v[i]!=v[i+1])b.push_back(i);

        }
        ll ans=0;
        if(a.size()!=b.size()){cout<<-1<<endl;continue;}
        for(int i=0;i<a.size();i++)ans+=abs(a[i]-b[i]);
        cout<<ans<<endl;

    }

    return 0;
}
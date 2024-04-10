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
        ll n,s;
        cin>>n>>s;
        string ans="";
        while(s>0)
        {
            ll u=s%10;
            ll p=n%10;
            if(p<=u){ans+=char(u-p+'0');n/=10;s/=10;continue;}
            u=s%100;
            if(u<p){ans="a";break;}
            if(u-p>=10){ans="a";break;}
            ans+=char(u-p+'0');n/=10;s/=100;

        }

        if(ans=="a"||n>0){cout<<-1<<endl;continue;}
        reverse(ans.begin(),ans.end());
        int u=0;
        while(u+1 <(int)ans.size() && ans[u]=='0')u++;
        for(int i=u;i<ans.size();i++)cout<<ans[i];
        cout<<endl;
    }

    return 0;
}
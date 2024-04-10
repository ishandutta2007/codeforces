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
        int n;
        string s,t;
        cin>>n>>s>>t;
        int i=0,ans=0;
        while(i<n)
        {
            int u=s[i]-'0';
            int v=t[i]-'0';
            if(u!=v){ans+=2;i++;continue;}
            if(u==0)
            {
                ans++;
                if(i+1==n)break;
                if(s[i+1]=='1' && t[i+1]=='1'){ans++;i+=2;continue;}
                i++;
                continue;
            }
            if(i+1==n)break;
            if(s[i+1]=='0' && t[i+1]=='0'){ans+=2;i+=2;continue;}
            i++;
        }
        cout<<ans<<endl;

    }
    return 0;
}
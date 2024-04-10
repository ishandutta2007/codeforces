#include <bits/stdc++.h>
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
        vector<int>u[5];
        cin>>n;
        for(int j=0;j<n;j++)
        {
            int fr[5]{0,0,0,0,0};
            string s;
            cin>>s;
            for(int i=0;i<s.size();i++)
            {
                fr[s[i]-'a']++;
            }
            for(int i=0;i<5;i++)
            {
                fr[i]-=(s.size()-fr[i]);
                u[i].push_back(fr[i]);
            }

        }
       int ans=0;
       for(int j=0;j<5;j++)
       {
           sort(u[j].begin(),u[j].end());
           if(u[j][n-1]<=0)continue;
           int r=u[j][n-1],g=1;
           for(int i=n-2;i>=0;i--)
           {
               if((r+u[j][i])<=0)break;
               g++;
               r+=u[j][i];
           }
           ans=max(ans,g);
       }
       cout<<ans<<endl;
    }
    return 0;
}
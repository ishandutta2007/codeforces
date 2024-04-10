#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int fr[27];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        memset(fr,0,sizeof fr);
        for(int i=0;i<n;i++)
        {
            char c;
            cin>>c;
            fr[c-'a']++;
        }
        int g=n/k;
        string ans="";
        for(int i=0;i<k;i++)
        {
            int u=0;
            for(int j=0;j<g;j++)
            {
                if(fr[j]==0)break;
                u++;
                fr[j]--;
            }
            ans+=char('a'+u);

        }
        cout<<ans<<endl;

    }
    return 0;
}
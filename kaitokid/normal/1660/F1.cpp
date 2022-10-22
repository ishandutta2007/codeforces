#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string s;
        cin>>n>>s;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int u=0;
            for(int j=i;j<n;j++)
            {
                if(s[j]=='+')u--;
                else u++;
              if((u>=0)&&((u%3)==0))ans++;
            }
        }
       cout<<ans<<endl;

    }
    return 0;
}
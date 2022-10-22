#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool th[29],vis[29];
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
        for(int i=0;i<28;i++)th[i]=vis[i]=false;
        for(int i=0;i<s.size();i++)
            th[s[i]-'a']=true;
        bool ans=true;
        for(int i=0;i<27;i++)
        {
            if(!th[i])continue;
            for(int j=0;j<27;j++)vis[j]=true;
            for(int u=0;u<s.size();u++)
            {
                vis[(s[u]-'a')]=true;
                if((s[u]-'a')!=i)continue;
            for(int j=0;j<27;j++)
            {
                if(th[j]&&(!vis[j]))ans=false;
                vis[j]=false;
            }

            }
        }
       if(ans)cout<<"YES"<<endl;
       else cout<<"NO"<<endl;
    }
    return 0;
}
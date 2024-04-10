#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool vis[40];
int main()
{
    int t;
    string s;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<30;i++)vis[i]=false;
        cin>>s;
        vis[s[0]-'A']=1;
        bool ans=true;
        for(int i=1;i<s.size();i++)
            if(s[i]!=s[i-1]&&vis[s[i]-'A']){ans=false;break;}
            else vis[s[i]-'A']=true;
            if(ans)cout<<"YES\n";
            else cout<<"NO\n";
    }
    return 0;
}
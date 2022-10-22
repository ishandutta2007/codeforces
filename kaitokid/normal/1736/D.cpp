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
        int n;
        string s;
        cin>>n>>s;
        n*=2;
        int u=0,v=0;
        for(int i=0;i<n;i++)
            if(s[i]=='0')u++;else v++;
        if((u%2)||(v%2)){cout<<-1<<endl;continue;}
        vector<int>g;
        int h=0;
        for(int i=0;i<n;i+=2)
        {
            if(s[i]==s[i+1])continue;
            if((s[i]-'0')==(h%2))g.push_back(i);
             else g.push_back(i+1);
             h++;
        }
        cout<<g.size()<<" ";
        for(int i=0;i<g.size();i++)cout<<g[i]+1<<" ";
        cout<<endl;
        for(int i=1;i<=n;i+=2)cout<<i<<" ";
        cout<<endl;

    }
    return 0;

}
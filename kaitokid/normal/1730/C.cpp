#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mn[200009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin>>q;
    while(q--)
    {
        string s;
        cin>>s;
        int n=s.size();
        mn[n]=10;
        for(int i=n-1;i>=0;i--)mn[i]=min(mn[i+1],s[i]-'0');
        string ans="";
        multiset<int>g;
        for(int i=0;i<n;i++)
            {
                int u=s[i]-'0';
                if(mn[i]!=u){
                u=min(9,u+1);
                g.insert(u);
                continue;
                }
                while(!g.empty())
                {
                    int h=(*g.begin());
                    if(h<=u){ans+=char('0'+h);g.erase(g.begin());continue;}
                    break;
                }
                ans+=char(u+'0');

            }
          while(!g.empty())
                {
                    int h=(*g.begin());
                    ans+=char('0'+h);g.erase(g.begin());
                }
          cout<<ans<<endl;


    }


    return 0;
}
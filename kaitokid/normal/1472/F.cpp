#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
map<int,int>mp[2];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,n,m;
    cin>>t;
    while(t--)
    {
        mp[0].clear();
        mp[1].clear();
        cin>>n>>m;
        set<int>st;
        for(int i=0;i<m;i++)
        {
            int r,c;
            cin>>r>>c;
            mp[r-1][c]=true;
            st.insert(c);
        }
     int u=2;
     for(set<int>::iterator it=st.begin();it!=st.end();it++)
     {
         int c=*it;
         if(u==2)
         {
             if(mp[0][c]&&mp[1][c])
             continue;
            if(mp[0][c])u=(c+1)%2;
            else u=(c)%2;
            continue;

         }

         if(mp[0][c]&&mp[1][c])break;
         if(mp[0][c]&&(u!=(c%2)))break;
         if(mp[1][c]&&(u==(c%2)))break;
         u=2;

     }
        if(u==2)cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}
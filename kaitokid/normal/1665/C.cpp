#include<bits/stdc++.h>
using namespace std;
int fr[200009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<=n;i++)fr[i]=0;
        int x;
        for(int i=1;i<n;i++)
        {
            cin>>x;
            fr[x]++;
        }
       multiset<int>st;
       multiset<int>g;
       int d=0,f=0;
       for(int i=0;i<=n;i++)
            if(fr[i])st.insert(fr[i]);
       st.insert(1);
       int ans=0;
       while(f<n)
       {
           ans++;
           multiset<int>tmp;
           multiset<int>::iterator it=g.begin();
           while(it!=g.end())
                {
                    int u=(*it);
                    f++;
                    u--;
                    if(u>0)tmp.insert(u);
                    it++;
                }
              g=tmp;
           if(!st.empty())
           {
               multiset<int>::iterator it=st.end();
               it--;
               f++;
               int u=(*it);
               u--;
               if(u>0)g.insert(u);
               st.erase(it);
           }
           else
           {
               if(g.empty())continue;
               multiset<int>::iterator it=g.end();
               it--;
               f++;
               int u=(*it)-1;
               g.erase(it);
               if(u>0)g.insert(u);
           }

       }
       cout<<ans<<endl;
    }
    return 0;
}
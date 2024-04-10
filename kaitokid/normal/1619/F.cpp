#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int fr[200009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        set<pair<int,int> >st;
        for(int i=1;i<=n;i++){st.insert({0,i});fr[i]=0;}
        int d=n%m,r=n/m;
        for(int g=0;g<k;g++)
        {
            for(int i=0;i<d;i++)
            {
                cout<<r+1<<" ";
                for(int j=0;j<r+1;j++)
                {
                    set<pair<int,int> >::iterator it=st.begin();
                    cout<<(*it).second<<" ";
                    fr[(*it).second]++;
                    st.erase(it);
                }
                cout<<endl;
            }
           for(int i=d;i<m;i++)
            {
                cout<<r<<" ";
                for(int j=0;j<r;j++)
                {
                    set<pair<int,int> >::iterator it=st.end();
                    it--;
                    cout<<(*it).second<<" ";
                    st.erase(it);
                }
                cout<<endl;
            }
           for(int i=1;i<=n;i++)st.insert({fr[i],i});
        }


    }

    return 0;
}
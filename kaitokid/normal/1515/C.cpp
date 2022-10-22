#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[109];
int main()
{
int t;
cin>>t;
while(t--)
{
    int n,m,x,z;
    cin>>n>>m>>z;
    cout<<"YES"<<endl;
    set<pair<int,int> >st;
    for(int i=1;i<=m;i++)
    st.insert({0,i});
    for(int i=0;i<n;i++)
    {
        cin>>x;
        set<pair<int,int> >::iterator it=st.begin();
        int u=(*it).first,v=(*it).second;
        cout<<v<<" ";
        st.erase(it);
        u+=x;
        st.insert({u,v});

    }
    cout<<endl;
}


    return 0;
}
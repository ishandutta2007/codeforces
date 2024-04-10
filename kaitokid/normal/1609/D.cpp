#include <bits/stdc++.h>

using namespace std;
int pr[200009],sz[200009],u;
int p(int x)
{
    if(x==pr[x])return x;
    return pr[x]=p(pr[x]);
}

    multiset<int>st;
int go()
{
    int ans=0;
    multiset<int>::iterator it=st.end();
    it--;
    for(int i=0;i<u;i++)
    {
        ans+=(*it);
        if(it==st.begin())break;
        it--;
    }
    ans--;
    return ans;
}
int main()
{
    int n,d;
    cin>>n>>d;
    for(int i=1;i<=n;i++){st.insert(1);pr[i]=i;sz[i]=1;}
     u=1;
    for(int i=0;i<d;i++)
    {
        int x,y;
        cin>>x>>y;
        x=p(x),y=p(y);
        if(x==y)
        {
            u++;
            cout<<go()<<endl;
            continue;
        }
        st.erase(st.lower_bound(sz[x]));
        st.erase(st.lower_bound(sz[y]));
        st.insert(sz[x]+sz[y]);
        sz[x]=sz[x]+sz[y];
        sz[y]=0;
        pr[y]=x;
        cout<<go()<<endl;


    }

    return 0;
}
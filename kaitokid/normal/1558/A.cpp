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
    int a,b;
    cin>>a>>b;
    int u= (a+b+1)/2,v=(a+b)/2;
    set<int>st;
    for(int i=0;i<=min(a,u);i++)
    {
        int r=a-i;
        if(r>v)continue;
        int g=u-i+v-r;
        if(g==b)st.insert(r+u-i);
    }
    swap(u,v);
    for(int i=0;i<=min(a,u);i++)
    {
        int r=a-i;
        if(r>v)continue;
        int g=u-i+v-r;
        if(g==b)st.insert(r+u-i);
    }
    cout<<st.size()<<endl;
    set<int>::iterator it=st.begin();
    while(it!=st.end())
    {
        cout<<(*it)<<" ";
        it++;
    }
    cout<<endl;
}

    return 0;
    }
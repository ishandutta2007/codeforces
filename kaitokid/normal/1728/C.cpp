#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int go(int x)
{
    int res=0;
    while(x>0){res++;x/=10;}
    return res;
}
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
    multiset<int>a,b;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a.insert(x);
    }
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        b.insert(x);
    }
    int ans=0;
    while(!a.empty())
    {
        multiset<int>::iterator it=a.end(),it2=b.end();
        it--,it2--;
        if((*it)==(*it2)){a.erase(it);b.erase(it2);continue;}
        ans++;
        if((*it)>(*it2))
        {
            int u=(*it);
            a.erase(it);
            a.insert(go(u));
            continue;
        }
        int u=(*it2);
            b.erase(it2);
            b.insert(go(u));
            continue;
    }
    cout<<ans<<endl;
    }
    return 0;
}
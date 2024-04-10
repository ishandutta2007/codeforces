#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    multiset<int>s;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        s.insert(x-a[i]);

    }
    int ans=0;
    while(!s.empty())
    {
        multiset<int>::iterator it=s.end();
        it--;
        int u=(*it);
        if(u<0)break;
        u*=-1;
        s.erase(it);
        multiset<int>::iterator it2=s.lower_bound(u);
        if(it2==s.end())break;
        ans++;
        s.erase(it2);
    }
    cout<<ans<<endl;

    }

    return 0;
}
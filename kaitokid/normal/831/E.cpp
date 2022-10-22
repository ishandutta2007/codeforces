#include <bits/stdc++.h>

using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
typedef long long ll;
set<int>a[100009];
int n,x;
vector<ll> v;
ordered_set ors;
int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        a[x].insert(i+1);
    ors.insert(i+1);
    }
    int u=0;
    for(int i=1;i<100001;i++)
    {
        if(a[i].empty())continue;
        set<int>::iterator it1,it2;
        it1=a[i].upper_bound(u);
        if(it1==a[i].end())it1=a[i].begin();
        v.push_back((*it1));
        it2=it1;
         u=(*it2);
        it2++;
         if(it2==a[i].end())it2=a[i].begin();
         while(it2!=it1)
         {

             v.push_back((*it2));
             u=(*it2);
        it2++;
         if(it2==a[i].end())it2=a[i].begin();

         }

    }

    ll ans=v[0];
//cout<<v.size()<<endl;
   for(int i=0;i<v.size()-1;i++)
    {
    ll y=ors.order_of_key(v[i+1]);
    y-=ors.order_of_key(v[i]);
    if(y<0)y+=ors.size();
    ans+=y;
    ors.erase(v[i]);
    }
cout<<ans;
//for(int i=0;i<v.size();i++ )cout<<v[i]<<" ";
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
vector<int> v;
int n,a[200009],m,ans[200009],k,p;
vector<pair<pair<int,int>,int> >q;
bool bl(int x,int y)
{
    if(a[x]>a[y])return true;
    if(a[x]<a[y])return false;
    if(x<y)return true;
    return false;


}
int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    ordered_set ors;
    for(int i=1;i<=n;i++){cin>>a[i];v.push_back(i);}
    sort(v.begin(),v.end(),bl);
        cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>k>>p;
        q.push_back(make_pair(make_pair(k,p),i));

    }

    sort(q.begin(),q.end());
    int u=0;
    for(int i=0;i<m;i++)
    {
        while(u<q[i].first.first){ors.insert(v[u]);u++;}
        ans[q[i].second]=(*ors.find_by_order(q[i].first.second-1));
    }
    for(int i=0;i<m;i++)cout<<a[ans[i]]<<endl;
    return 0;
}
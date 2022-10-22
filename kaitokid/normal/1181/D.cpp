#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
ll n,m,q;
vector<pair<ll,ll> > v;
ordered_set ors;
int ans[500009];
vector<pair<ll,int> >rq;
int h[500009];
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
ll x;
cin>>n>>m>>q;
for(int i=0;i<n;i++){cin>>x;h[x]++;}
    for(int i=1;i<=m;i++)v.push_back(make_pair(h[i],i));
    for(int i=0;i<q;i++)
    {
        cin>>x;
        x-=n;
        rq.push_back(make_pair(x,i));

    }
    sort(v.begin(),v.end());
    sort(rq.begin(),rq.end());
    int ques=0;
    ll now=1,num=1;
    ll i=0;
ors.insert(v[0].second);
    while(i<m-1)
    {

        ll now2=now+(v[i+1].first-v[i].first)*num;
        while(ques<q&&rq[ques].first<now2){
                ll res=(rq[ques].first-now)%(num);

                ans[rq[ques].second]=(*ors.find_by_order(res));ques++;}
       now=now2;
       num++;
       i++;
       ors.insert(v[i].second);
    }
     while(ques<q){
                ll res=(rq[ques].first-now)%(num);

                ans[rq[ques].second]=(*ors.find_by_order(res));ques++;}
    for(int i=0;i<q;i++)cout<<ans[i]<<endl;
    return 0;
}
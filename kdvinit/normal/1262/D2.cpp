/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define int long long

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

bool cmp(vector<int>& a,vector<int>& b)
{
    if(a[0]!=b[0])
        return (a[0]>b[0]);
    else
        return (a[1]<b[1]);
}

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    vector< vector<int> > b(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b[i].push_back(a[i]);
        b[i].push_back(i);
    }
    sort(b.begin(),b.end(),cmp);

    int m; cin>>m;
    int fans[m+1];

    vector< vector<int> > req(m);
    for(int i=0;i<m;i++)
    {
        int k,p;
        cin>>k>>p;
        req[i].push_back(k);
        req[i].push_back(p);
        req[i].push_back(i+1);
    }

    sort(req.begin(),req.end());

    ordered_set ans;

    int len=0;
    for(int i=0;i<m;i++)
    {
        int x=req[i][0];
        int y=req[i][1];
        int z=req[i][2];

        while(len<x)
        {
            int p=b[len][0];
            int q=b[len][1];

            ans.insert(q);
            len++;
        }

        int l=*ans.find_by_order(y-1);
        fans[z]=a[l];
    }

    for(int i=1;i<=m;i++) cout<<fans[i]<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
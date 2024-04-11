#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
#define int long long


int n, k;
int c[100500];
int a[100500];
vector<int> v[100500];

main()
{
    cin>>n>>k;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        v[a[i]].push_back(i);
    }
    int cur=1;
    int f=0;
    for (int i=0; i<100500; i++)
        for (int j=0; j<v[i].size(); j++)
    {
        if (v[i].size()>k)
        {
            cout<<"NO\n";
            return 0;
        }
        int q=v[i][j];
        c[q]=cur;
        cur++;
        if (cur>k)
        {
            cur=1;
            f=1;
        }
    }
    if (f==0)
        cout<<"NO\n";
    else
    {
        cout<<"YES\n";
        for (int i=1; i<=n; i++)
            cout<<c[i]<<" ";
        cout<<"\n";
    }
}
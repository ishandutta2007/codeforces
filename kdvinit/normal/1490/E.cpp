/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    pair<int,int> a[n];
    for(int i=0;i<n;i++)
    {
         int x; cin>>x;
         a[i]={x,i};
    }

    sort(a,a+n);

    int sum[n]={0};
    int cur=0;
    for(int i=0;i<n;i++)
    {
        cur+=a[i].first;
        sum[i]=cur;
    }

    vector<int> pos;

    for(int i=n-1;i>=0;i--)
    {
        if(i==n-1)
        {
            int j=i;
            while(i>=0 && a[i].first==a[j].first)
            {
                pos.push_back(a[i].second);
                i--;
            }
            i++;
            continue;
        }

        if(sum[i]<a[i+1].first) break;

        int j=i;
        while(i>=0 && a[i].first==a[j].first)
        {
            pos.push_back(a[i].second);
            i--;
        }
        i++;
    }

    sort(pos.begin(),pos.end());

    int m=pos.size();
    cout<<m<<endl;

    for(int i=0;i<m;i++)
    {
        cout<<pos[i]+1<<" ";
    }
    cout<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
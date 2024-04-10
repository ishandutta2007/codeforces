/*
K.D. Vinit  |,,|
*/

#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;
#define int long long

#define len 6e5
int infy=1e10;
int neg_infy=(-1)*infy;

int a[(int)len],b[(int)len];

int LIS(int strt,int nd)
{
    if(strt+1==nd) return 0;

    vector<int> seq,pos;

    for(int i=strt+1;i<nd;i++)
    {
        if( a[strt] > a[i] ) continue;
        if( a[i] > a[nd] ) continue;

        if(seq.size()==0)
        {
            seq.push_back(a[i]);
            continue;
        }

        if(seq.back()<=a[i])
        {
            seq.push_back(a[i]);
        }
        else
        {
            int ind=upper_bound(seq.begin(),seq.end(),a[i])-seq.begin();
            seq[ind]=a[i];
        }
    }

    int m=seq.size();
    return m;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int n,k;
    cin>>n>>k;

    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) a[i]-=i;
    for(int i=1;i<=k;i++) cin>>b[i];
    sort(b+1,b+k+1);

    a[0]=neg_infy; a[n+1]=infy;
    b[0]=0; b[k+1]=n+1;

    for(int i=2;i<=k;i++)
    {
        if( a[b[i-1]] > a[b[i]] ) { cout<<-1<<endl; return 0; }
    }

    int ans=n-k;

    for(int i=0;i<=k;i++)
    {
        ans-=LIS(b[i],b[i+1]);
    }

    cout<<ans<<endl;

    return 0;
}
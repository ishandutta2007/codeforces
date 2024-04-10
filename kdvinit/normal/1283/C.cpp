/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define int long long

void solve()
{
    int n;
    cin>>n;

    int a[n+1],freq[n+1]={0},help,index;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        freq[a[i]]++;
    }

    if(freq[0]==0)
    {
        for(int i=1;i<=n;i++) cout<<a[i]<<" ";
        cout<<endl;
        return;
    }

    vector<int> aa,b,c;
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=0) continue;
        if(freq[i]==0) { c.push_back(i); freq[i]=1; }
        else aa.push_back(i);
    }

    for(int i=1;i<=n;i++)
    {
        if(freq[i]==0) b.push_back(i);
    }
    
    for(int i=0;i<aa.size();i++)
    {
        a[aa[i]]=b[i];
    }

    int m=c.size();
    if(m==1)
    {
        a[c[0]]=b[0];
        a[aa[0]]=c[0];
    }
    else
    {
        for(int i=0;i<m;i++)
        {
            a[c[i]]=c[(i+1)%m];
        }
    }

    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
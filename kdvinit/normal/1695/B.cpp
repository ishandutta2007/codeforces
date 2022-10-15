/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

bool solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    if(n%2==1) return true;

    int m1=1e10, m2=1e10;
    int m1i, m2i;

    for(int i=1; i<=n; i++)
    {
        if(i%2==1)
        {
            if(a[i]<m1) { m1=a[i]; m1i=i; }
        }
        else
        {
            if(a[i]<m2) { m2=a[i]; m2i=i; }
        }
    }

    if(m1>m2) return true;
    if(m1<m2) return false;

    if(m1i>m2i) return true;
    else return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--)
    {
        if(solve()) cout<<"Mike"<<endl;
        else cout<<"Joe"<<endl;
    }
    return 0;
}
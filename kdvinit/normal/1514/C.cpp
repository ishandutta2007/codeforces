/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int GCD(int x, int y)
{
    if(x==0 || y==0) return x+y;
    else return GCD(y, x%y);
}

void solve()
{
    int n;
    cin>>n;

    int a[n];

    int ans=1;
    for(int i=1; i<n; i++)
    {
        if(GCD(i, n)==1) 
        { 
            a[i]=1; 
            ans*=i; 
            ans%=n;
        }
        else a[i]=0;
    }

    if(ans%n!=1) a[ans%n]=0;

    vector<int> b;
    for(int i=1; i<n; i++)
    {
        if(a[i]==1) b.push_back(i);
    }

    cout<<b.size()<<endl;
    for(int i=0; i<b.size(); i++) cout<<b[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
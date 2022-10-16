/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

#define $Prime_Length 2001
bool Is_It_Prime[$Prime_Length];

int Make_Prime()
{
    for(int i=2;i<$Prime_Length;i++) Is_It_Prime[i]=1;
    for(int i=2;i*i<$Prime_Length;i++) { if(Is_It_Prime[i]==1) for(int j=i*i;j<$Prime_Length;j+=i) Is_It_Prime[j]=0; }
    return 0;
}
int Implement_Make_Prime=Make_Prime();

void solve()
{
    int n,m;
    cin>>n;

    m=n;
    while(Is_It_Prime[m]!=1) m++;
    cout<<m<<endl;
    m-=n;

    for(int i=1;i<n;i++) cout<<i<<" "<<i+1<<endl;
    cout<<n<<" "<<1<<endl;

    int k=(n/2);
    for(int i=1;1;i++)
    {
        if(m==0) break;
        m--;
        cout<<i<<" "<<(i+k)<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

#define $Prime_Length 500001     //Max length here is 519160
bool Is_It_Prime[$Prime_Length];
int Make_Prime()
{
    for(int i=2;i<$Prime_Length;i++) Is_It_Prime[i]=1;
    for(int i=2;i*i<$Prime_Length;i++) { if(Is_It_Prime[i]==1) for(int j=i*i;j<$Prime_Length;j+=i) Is_It_Prime[j]=0; }
    return 0;
}
int Implement_Make_Prime=Make_Prime();

int nxt_prime(int n)
{
    while(Is_It_Prime[n]==0) n++;
    return n;
}


void solve()
{
    int n;
    cin>>n;

    int x=nxt_prime(1+n);
    int y=nxt_prime(x+n);
    cout<<x*y<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
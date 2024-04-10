/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

#define $Prime_Length 100001     //Max length here is 519160
bool Is_It_Prime[$Prime_Length];
/**Note that 0 and 1 or not prime here **/
int Make_Prime()
{
    for(int i=2;i<$Prime_Length;i++) Is_It_Prime[i]=1;
    for(int i=2;i*i<$Prime_Length;i++) { if(Is_It_Prime[i]==1) for(int j=i*i;j<$Prime_Length;j+=i) Is_It_Prime[j]=0; }
    return 0;
}
int Implement_Make_Prime=Make_Prime();


void solve()
{
    int p,q;
    cin>>p>>q;

    int q2=q;

    if(p%q!=0) { cout<<p<<endl; return; }

    vector<int> factors;
    for(int i=2;i*i<=q;i++)
    {
        if(Is_It_Prime[i]==0) continue;
        if(q%i!=0) continue;
        factors.push_back(i);
        while(q%i==0) q/=i;
    }
    if(q!=1) factors.push_back(q);


    int ans=p;
    for(int i=0;i<factors.size();i++)
    {
        int power1=0;
        int power2=0;
        int x=factors[i];
        int temp=q2;
        while(temp%x==0) { temp/=x; power1++; }
        temp=p;
        while(temp%x==0) { temp/=x; power2++; }
        //cout<<i<<" "<<factors[i]<<" "<<power1<<" "<<power2<<endl;
        power2-=power1;
        power2++;
        temp=pow(x,power2);
        ans=min(ans,temp);
    }
    ans=p/ans;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}
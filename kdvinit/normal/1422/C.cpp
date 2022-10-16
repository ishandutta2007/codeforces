/*
K.D. Vinit
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

int mod=1e9+7;
int mx=1e5;
int nC2[100001];
int val[100001];

int Power(int a,int b)
{
    int result=1; a%=mod;
    while(b) {   if(b%2==1)  result*=a;     a*=a;     a%=mod;     result%=mod;    b/=2; }
    if(result<0) result+=mod;
    return result;
}

void do_it()
{
    for(int i=0;i<=mx;i++)
    {
        nC2[i]=i;
        nC2[i]*=(i+1);
        nC2[i]/=2;
        nC2[i]%=mod;
    }

    val[0]=0;
    for(int i=1;i<=mx;i++)
    {
        val[i]=i*Power(10,i-1);
        val[i]%=mod;
        val[i]+=val[i-1];
        val[i]%=mod;
    }
}



void solve()
{
    string s;
    cin>>s;

    int n=s.size();
    do_it();

    int ans=0;
    for(int i=0;i<n;i++)
    {
        int x=s[i];
        x-=48;
        int y=val[n-1-i];
        int z=nC2[i];
        z*=Power(10,(n-1-i));
        z%=mod;
        y+=z;
        y%=mod;
        y*=x;
        y%=mod;
        ans+=y;
        ans%=mod;
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
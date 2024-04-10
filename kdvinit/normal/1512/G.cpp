/*
K.D. Vinit  |,,|
*/
#pragma GCC optimize("unroll-loops") 
#pragma GCC optimize("O3") 
#pragma GCC target("avx2")
#include<bits/stdc++.h>
using namespace std;

const int N = 1e7 + 1;
int Sum_Factors[N];
int Min_n[N];

int Sieve()
{
    for(int i=1; i<N; i++) Sum_Factors[i]=i+1;

    Sum_Factors[1]=1;
    for(int i=2; i*i<N; i++)
    {
        int cnt=i;
        for(int j=i*i; j<N; j+=i, cnt++)
        {
            if(Sum_Factors[j]==-1) continue;

            Sum_Factors[j] += i;
            if(i!=cnt) Sum_Factors[j] += cnt;

            if(Sum_Factors[j]>=N) Sum_Factors[j]=-1;
        }
    }

    for(int i=1; i<N; i++) Min_n[i]=-1;

    for(int i=1; i<N; i++)
    {
        int x = Sum_Factors[i];
        if(x>=N || x==-1) continue;
        if(Min_n[x]==-1) Min_n[x]=i;
    }

    return 0;
}
int Implement_Sieve=Sieve();


void solve()
{
    int c;
    cin>>c;

    cout<<Min_n[c]<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
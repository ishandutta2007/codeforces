/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

int mod=1000000007;

void solve()
{
    int n;
    cin>>n;

    int nda=0,ndb=0,ndc=0,cnt=1;
    for(int i=1;i<=n;i++)
    {
        char x;
        cin>>x;
        if(x=='a') { nda+=cnt; nda%=mod; }
        if(x=='b') { ndb+=nda; ndb%=mod; }
        if(x=='c') { ndc+=ndb; ndc%=mod; }
        if(x=='?') { ndc*=3; ndc+=ndb; ndb*=3; ndb+=nda; nda*=3; nda+=cnt; ndc%=mod; ndb%=mod; nda%=mod; cnt*=3; cnt%=mod; }
    }

    cout<<ndc<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
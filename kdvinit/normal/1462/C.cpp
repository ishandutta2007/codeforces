/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

void solve()
{
    int x;
    cin>>x;

    if(x>45) { cout<<-1<<endl; return; }

    vector<int> a;
    int cnt=9;
    while(x>0)
    {
        if(x<=cnt) { a.push_back(x); break; }

        x-=cnt;
        a.push_back(cnt);
        cnt--;
    }
    sort(a.begin(),a.end());

    for(int i=0;i<a.size();i++) cout<<a[i];
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}
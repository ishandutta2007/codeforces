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
    string s;
    cin>>s;
    int n=s.size();
    int m=(n+1)/2;

    char a[n+1];
    for(int i=1;i<=n;i++)
    {
        int x=(i+1)/2;
        if(i%2==1)
        {
            a[i]=s[m-x];
        }
        else
        {
            a[i]=s[m+x-1];
        }
    }

    for(int i=1;i<=n;i++) cout<<a[i];
    cout<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
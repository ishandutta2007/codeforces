#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    long n;
    cin>>n;
    if(n==0)cout<<1;
    else if(n%4==1)cout<<8;
    else if(n%4==2)cout<<4;
    else if(n%4==3)cout<<2;
    else if(n%4==0)cout<<6;
    return 0;
}
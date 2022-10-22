#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);

    long long d=0,x,k,l;
    cin>>k>>l;
    x=k;
    if(k==l){cout<<"YES\n"<<0;return 0;}
    while(k<=l){
        k*=x;
        d++;
        if(k==l){cout<<"YES\n"<<d;return 0;}
    }
    cout<<"NO";
    return 0;
}
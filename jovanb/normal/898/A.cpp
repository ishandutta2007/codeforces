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
    if(n%10==0){cout<<n;return 0;}
    if(n%10<5){cout<<n-(n%10);return 0;}
    cout<<n+10-(n%10);
    return 0;
}
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
#define int long long

main()
{
    int n;
    cin>>n;
    if ((n%4==0) or (n%4==3))
        cout<<"0\n";
    else
        cout<<"1\n";

}
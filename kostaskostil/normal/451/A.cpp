#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#define int long long
#define fi first
#define se second

using namespace std;

main()
{
    int m, n;
    cin>>m>>n;
    if (min(m,n)%2==0)
        cout<<"Malvika\n";
    else
        cout<<"Akshat\n";
}
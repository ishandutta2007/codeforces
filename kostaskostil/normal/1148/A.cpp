#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

#define int long long

using namespace std;

const int nmax=500500;


main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b, c;
    cin>>a>>b>>c;
    cout<<2*c+2*min(a, b)+(a!=b)<<"\n";
}
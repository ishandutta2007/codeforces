#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;

int a[100500];
vector<int> v;
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b, c;
    cin>>a>>b>>c;
    int t=(c*a+b-1)/b;
    cout<<t-c<<"\n";

}
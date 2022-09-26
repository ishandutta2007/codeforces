#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

#define nmax 500500

typedef long long ll;
#define int ll

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, a1, a2, a3, b1, b2, b3;
    cin>>n>>a1>>a2>>a3>>b1>>b2>>b3;
    int mn = min(a1, b2)+min(a2, b3) + min(a3, b1);

    int c = b1;
    b1 = b2;
    b2 = b3;
    b3 = c;

    cout<<max(0ll, max(max(a1+b1, a2+b2), a3+b3)-n)<<" "<<mn<<"\n";
}
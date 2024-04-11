#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

int n;
int a[300500];

main()
{
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];
    sort(a, a+n);
    cout<<abs(min(a[n-2]-a[0], a[n-1]-a[1]));
    return 0;
}
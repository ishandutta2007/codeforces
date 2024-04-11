#include <bits/stdc++.h>
#define int long long

using namespace std;

main()
{
    map<int, int> m;
    int n;
    int x;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>x, m[x]++;
    int cnt=0;
    for (pair<int, int> pa: m)
    {
        cnt=max(0ll, cnt-pa.second);
        cnt+=pa.second;
    }
    cout<<n-cnt<<"\n";
    return 0;
}
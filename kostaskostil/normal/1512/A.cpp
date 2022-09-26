#include <bits/stdc++.h>

using namespace std;

main()
{
    int ___;
    cin>>___;
    while (___--)
    {
        int n, i=0;
        cin>>n;
        vector<pair<int, int> > v(n);
        int sum=0;
        for (auto& pa : v)
        {
            cin>>pa.first;
            pa.second=++i;
            sum+=pa.first;
        }
        sort(v.begin(), v.end(), [&](const auto& lhs, const auto& rhs){ return abs(lhs.first * n - sum) > abs(rhs.first * n - sum); });
        cout<<v[0].second<<"\n";
    }
}
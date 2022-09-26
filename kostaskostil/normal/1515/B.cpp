#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
#define int ll

unordered_set<int> st;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i=1; i*i<=1e9; i++)
        st.insert(2*i*i), st.insert(4*i*i);

    int ___;
    cin>>___;
    while (___--)
    {
        int n;
        cin>>n;
        if (st.count(n))
            cout<<"YES\n";
        else
            cout<<"NO\n";

    }
}
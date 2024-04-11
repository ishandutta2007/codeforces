#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int nmax=5e5+100;
#define int long long

set<int> st;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++)
    {
        st.clear();
        int n, k;
        cin>>n>>k;
        for (int x, i=0; i<n; i++)
            cin>>x, st.insert(x);
        if (st.size()>k)
            cout<<"-1\n";
        else
        {
            cout<<k*n<<"\n";
            for (int i=0; i<n; i++)
            {
                for (int j:st)
                    cout<<j<<" ";
                for (int j=1; j<=k-st.size(); j++)
                    cout<<1<<" ";
            }
            cout<<"\n";
        }
    }
}
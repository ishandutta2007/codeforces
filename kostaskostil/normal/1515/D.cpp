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
        int n, l, r;
        cin>>n>>l>>r;

        unordered_map<int, int>lt, rt;

        for (int i=0; i<l; i++)
        {
            int x;
            cin>>x;
            lt[x]++;
        }
        for (int i=0; i<r; i++)
        {
            int x;
            cin>>x;
            rt[x]++;
        }
        int alr=0;
        for (auto& pa : lt)
        {
            int d = min(pa.se, rt[pa.fi]);
            pa.se-=d;
            rt[pa.fi]-=d;
            alr+=d;
            alr+=min(pa.se, rt[pa.fi]);
        }
        int lc=0, rc=0, tl=0, tr=0;
        for (auto& pa : lt)
        {
            lc+=pa.se;
            tl+=pa.se/2;
        }
        for (auto& pa : rt)

        {
            rc+=pa.se;
            tr+=pa.se/2;
        }
        n-=2*alr;

//        cout<<n<<" "<<lc<<" "<<rc<<" "<<tl<<" "<<tr<<"\n";
        int res=0;
        if (lc > rc)
        /// lc -> ostavim lc - rc, iz nih 2*tl ok;
        {
            lc -= rc;
            res = max<int>(0, lc - 2*tl);
        }
        else
        {
            rc -= lc;
            res = max<int>(0, rc - 2*tr);
        }
//        cout<<res<<"\n";
        cout<<(n)/2 + res/2<<"\n";
    }
}
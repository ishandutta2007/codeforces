#include "bits/stdc++.h"

#define fi first
#define se second
#define pb push_back

using namespace std;

#define nmax 1000500
typedef long long ll;
#define int ll

unordered_multiset<int> add[nmax];
unordered_multiset<int> del[nmax];

/*
1 16
1 1
1 1
1 1
0 4
4 5
0 5
5 0
4 4
3 3
2 9
10 1
11 0
3 6
3 5
3 6
5 3
3 3
*/

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    vector<pair<int, int> > v(n);
    set<pair<int, int> > st = {{-1, nmax-2}, {nmax-2, -1}};
    for (auto& pa:v)
        cin>>pa.fi>>pa.se;
    for (int i=0; i<m; i++)
    {
        int x, y;
        cin>>x>>y;

        if ( st.lower_bound({x, -1})->se > y )
            continue;
        if ( st.lower_bound({x, -1})->fi == x )
            st.erase(st.lower_bound({x, -1}));
        st.insert({x, y});
        while ( prev(st.lower_bound({x, -1}))->se <= y )
            st.erase(prev(st.lower_bound({x, -1})));

//        cout<<"sb\n";
//        for (auto pa:st)
//            cout<<pa.fi<<" "<<pa.se<<"\n";
//        cout<<"se\n";
    }
    vector<pair<int, int> > vx;
    for (auto pa:st)
    {
        vx.pb(pa);
//        cout<<pa.fi<<" "<<pa.se<<"\n";
    }
    for (auto pa:v)
        for (size_t i=0; i+1<vx.size(); i++)
    {
        int dl=vx[i].fi+1-pa.fi;
        int dr=vx[i+1].fi-pa.fi;
        int h=vx[i+1].se+1-pa.se;
        dl=max(0ll, dl);
        if ((h>0) and (dr>=dl))
        {
            add[dl].insert(h);
            del[dr].insert(h);
//            cout<<"add "<<dl<<" "<<h<<"\n";
//            cout<<"del "<<dr<<" "<<h<<"\n";
        }
    }

    multiset<int> cur;
    int ans=1e9;
    for (int i=0; i<nmax; i++)
    {
        for (int j:add[i])
            cur.insert(j);

        if (cur.size())
            ans=min(ans, i+(*prev(cur.end())));
        else
            ans=min(ans, i);

        for (int j:del[i])
            cur.erase(cur.find(j));
    }
    cout<<ans<<"\n";
}
#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
#define int ll

int n;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    cin>>n;
    vector<int> v(n);
    for (int& i:v)
        cin>>i;
    set<pair<int, int> > st;
    for (int i=0; i<n; i++)
        st.insert({v[i], i});
    int c=0;
    for (auto pa:st)
        v[pa.se]=c++;

    vector<pair<int, int> > ans;
    for (c=0; c<n; c++)
    {
        vector<int> pos(n);
        for (int i=0; i<n; i++)
            pos[v[i]]=i;
        for (int i=v[c]-1; i>=0; i--)
            if (pos[i]>c)
            {
                ans.pb({c, pos[i]});
                swap(v[c], v[pos[i]]);
            }
    }
    cout<<ans.size()<<"\n";
    for (auto pa:ans)
        cout<<pa.fi+1<<" "<<pa.se+1<<"\n";
}
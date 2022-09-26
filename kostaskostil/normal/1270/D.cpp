#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;
const int nmax=5e5+100;
typedef long long ll;
#define int ll

int n;
int a[nmax];
set<int> st;

pair<int, int> ask(){
    cout<<"? ";
    for (int i:st)
        cout<<i<<" ";
    cout<<endl;
    int x, y;
    cin>>x>>y;
    return {x, y};
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;

    for (int i=1; i<=k+1; i++)
        st.insert(i);
    map<pair<int, int>, int> mp;
    for (int i=1; i<=k+1; i++)
    {
        st.erase(i);
        mp[ask()]++;
        st.insert(i);
    }
    vector<pair<pair<int, int>, int> > v;
    for (auto pa:mp)
        v.pb(pa);
    auto pa1=v[0];
    auto pa2=v[1];
    if (pa2.fi.se<pa1.fi.se)
        swap(pa1, pa2);
    cout<<"! "<<pa2.se<<"\n";
    return 0;
}
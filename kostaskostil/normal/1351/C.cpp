#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;
const int nmax=5e5+100;
#define int long long


main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++)
    {
set<pair<pair<int, int>, pair<int, int> > > st;
int x=0;
int y=0;
int ans=0;
string s;
cin>>s;
for (char c:s)
{
    pair pa(x, y);
    auto pa2=pa;
    if (c=='W') pa2.se++;
    if (c=='E') pa2.se--;
    if (c=='N') pa2.fi++;
    if (c=='S') pa2.fi--;
    if (st.count({min(pa, pa2), max(pa, pa2)}))
        ans++;
    else
        ans+=5, st.insert({min(pa, pa2), max(pa, pa2)});
    x=pa2.fi, y=pa2.se;
}
cout<<ans<<"\n";
    }

    return 0;
}
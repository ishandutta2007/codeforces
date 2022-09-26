#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

const int nmax = 5e5 + 100;

typedef long long ll;
#define int ll

set <pair<int, int> > ans;
int n;
vector<int> boris(int v)
{
    cout<<"? "<<v+1<<endl;
    vector<int>res(n);
    for (int i = 0; i<n; i++)
    {
        cin>>res[i];
        if (res[i] == 1)
        {
            ans.insert({min(i+1, v+1), max(i+1, v+1)});
        }
    }
    return res;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;

    auto d = boris(0);
    vector<int> ev, odd;
    for (int i=1; i<n; i++)
    {
        if (d[i]%2)
            odd.pb(i);
        else
            ev.pb(i);
    }

    if (ev.size() > odd.size())
        swap(ev, odd);
    for (int i : ev)
        boris(i);
    cout<<"!\n";
    for (auto pa : ans)
        cout<<pa.fi<<" "<<pa.se<<"\n";
    cout<<endl;
}
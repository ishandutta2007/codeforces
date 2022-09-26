#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

const int nmax=1000500;
typedef long long ll;
#define int ll

istream& operator >> (istream& is, vector<int>& v)
{
    for (int& i:v) is>>i;
    return is;
}

void sadness()
{
    cout<<"NO\n";
    exit(0);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    set<pair<int, int> > lt;
    int n;
    cin>>n;
    vector<int> v(n+1);
    vector<int> pos_ans(2*n+1);
    vector<int> ans(n+1);
    int c = 0;
    for (int i=1; i<=2*n; i++)
    {
        string s;
        cin>>s;
        if (s=="+")
        {
            c++;
            pos_ans[i]=c;
            lt.insert({i, 0});
        }
        else
        {
            int x;
            cin>>x;
            v[x]=i;
            lt.insert({i, x});
        }
    }
    for (int i=1; i<=n; i++)
    {
        int p = v[i];
        lt.erase({p, i});
        auto pt = lt.lower_bound({p, 0});
        if (pt == lt.begin())
        {
            sadness();
        }
        pt = prev(pt);
        if (pt->se != 0)
            sadness();
        ans[pos_ans[pt->fi]] = i;
        lt.erase(pt);
    }
    cout<<"YES\n";
    for (int i=1; i<=n; i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
}
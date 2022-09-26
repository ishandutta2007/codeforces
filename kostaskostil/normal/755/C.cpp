#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

const int nmax=1000500;
typedef long long ll;
#define int ll

int p[nmax];

int pr(int v)
{
    if (p[v]==v)
        return v;
    return p[v]=pr(p[v]);
}

void un(int u, int v)
{
    u=pr(u);
    v=pr(v);
    p[u]=v;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        p[i]=i;
    for (int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        un(i, x);
    }
    unordered_set<int> st;
    for (int i=1; i<=n; i++)
        st.insert(pr(i));
    cout<<st.size()<<"\n";
}
#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

#define int long long

using namespace std;

const int nmax=500500;
int n;
int p[nmax];
int pos[nmax];
vector<pair<int, int> > v;

void sw(int i, int j)
{
    swap(p[i], p[j]);
    v.pb({i, j});
}

void swp(int i, int j)
{
    if (i==j)
        return;
    if (i>j)
        swap(i, j);
    if (i==1)
    {
        if (j<=n/2)
            sw(j, n), sw(1, n), sw(j, n);
        else
            sw(i, j);
        return;
    }
    if (j==n)
    {
        if (i<=n/2)
            sw(i, j);
        else
            sw(i, 1), sw(1, n), sw(i, 1);
        return;
    }
    if ((i<=n/2) and (j<=n/2))
        sw(i, n), sw(j, n), sw(i, n);
    if ((i<=n/2) and (j>n/2))
        sw(i, n), sw(j, 1), sw(1, n), sw(i, n), sw(j, 1);
    if ((i>n/2) and (j<=n/2))
        sw(i, 1), sw(j, n), sw(1, n), sw(i, 1), sw(j, n);
    if ((i>n/2) and (j>n/2))
        sw(i, 1), sw(j, 1), sw(i, 1);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>p[i], pos[p[i]]=i;
    for (int i=1; i<n; i++)
        if (p[i]!=i)
    {
        pos[p[i]]=pos[i];
        swp(i, pos[i]);
        pos[i]=i;
    }
    cout<<v.size()<<"\n";
    for (auto pa:v)
        cout<<pa.fi<<" "<<pa.se<<"\n";
}
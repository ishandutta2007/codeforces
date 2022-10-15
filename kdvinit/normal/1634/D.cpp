/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

int q;
int query(int i, int j, int k)
{
    cout<<"? "<<i<<" "<<j<<" "<<k<<endl;
    cin>>q;
    return q;
}

void print_ans(int i, int j)
{
    cout<<"! "<<i<<" "<<j<<endl;
    return;
}

map<int, vector<int>> ind;

void check(int i1, int i2, int dif)
{
    vector<int> cur = ind[dif];

    int n = cur.size();

    for(int i=0; i+1<n; i++)
    {
        int x = cur[i];
        int y = cur[i+1];
        query(i1, x, y);
        if(q>dif)
        {
            print_ans(x, y);
            return;
        }
    }

    print_ans(i1, i2);
    return;
}

void solve()
{
    int n;
    cin>>n;

    ind.clear();

    int mn = 1e10;
    int mxv = -1;
    int mxi = -1;

    for(int i=1; i<=n; i++)
    {
        if(i==1 || i==2) continue;

        query(1, 2, i);
        mn = min(mn, q);

        ind[q].push_back(i);

        if(q>mxv)
        {
            mxv=q;
            mxi=i;
        }
    }

    if(mxv==mn)
    {
        check(1, 2, mxv);
        return;
    }

    int pos1 = mxi;

    mn = 1e10;
    mxv = -1;
    mxi = -1;

    for(int i=1; i<=n; i++)
    {
        if(i==1 || i==pos1) continue;

        query(1, pos1, i);
        mn = min(mn, q);

        ind[q].push_back(i);

        if(q>mxv)
        {
            mxv=q;
            mxi=i;
        }
    }

    if(mxv==mn)
    {
        print_ans(1, pos1);
        return;
    }

    print_ans(mxi, pos1);
}

int32_t main()
{
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
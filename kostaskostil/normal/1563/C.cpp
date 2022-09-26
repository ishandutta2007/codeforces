#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
#define int ll

const int nmax = 100500;
int p[nmax];
vector<int> ans;
bool ok;
int pos(int x)
{
    for (int i =1 ;; i++)
        if (p[i] == x)
            return i;
}

void oper(int q)
{
    reverse(p+1, p+q+1);
    ans.pb(q);
}

void solve(int n)
{
    if (n==1)
    {
        ok = true;
        return;
    }
    int i = pos(n);
    if (i%2==0) return;
    oper(i);
    i = pos(n-1);
    if (i%2==1) return;
    oper(i-1);
    oper(n);
    oper(n - i + 2);
    oper(n);
    solve(n-2);
    // i -> n + 1 - i;
    //
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _;
    cin>>_;
    while (_--)
    {
        int n;
        ok = false;
        cin>>n;
        for (int i=1; i<=n; i++)
            cin>>p[i];
        ans.clear();
        solve(n);
        if (ok)
        {
            cout<<ans.size()<<"\n";
            for (int i : ans)
                cout<<i<<" ";
            cout<<"\n";
        }
        else
        {
            cout<<"-1\n";
        }
    }
}
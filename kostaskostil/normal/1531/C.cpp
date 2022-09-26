#pragma GCC optimize("O3")

#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second

typedef long long ll;

using namespace std;

map<int, vector<string> > otveti;

int n;
vector<int> h;

void gen()
{
    vector<string> ans(n);
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            ans[i].pb('.');
    for (int i=0; i<n; i++)
        for (int j=0; j<=h[i]; j++)
            ans[i][j] = ans[j][i] = 'o';
    int s=0;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (ans[i][j] =='o')
                s++;
    otveti[s] = ans;
}

void perebor(int x)
{
//    cout<<x<<": ";
//    for (int i :h)
//        cout<<i<<" ";
//    cout<<"\n";

    if (x==n)
        return;
    int h0 = n-1;
    if (x > 0)
        h0 = h[x-1];
    for (h[x] = h0; h[x] >= x; h[x]--)
    {
        gen();
        perebor(x+1);
    }
    h[x] = 0;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m;
    cin>>m;
    for (int i = 1; ; i++)
    {
        n = i;
        h.resize(n);
        perebor(0);

        if (otveti.count(m))
        {
            cout<<i<<"\n";
            reverse(otveti[m].begin(), otveti[m].end());
            for (string s : otveti[m])
                cout<<s<<"\n";
            break;
        }

        if (clock()*1.0 / CLOCKS_PER_SEC > 1.0)
        {
            cout<<"-1\n";
            break;
        }
    }

}
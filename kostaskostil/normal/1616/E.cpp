#include <bits/stdc++.h>
#define y1 y_1
#define fi first
#define se second
#define pb push_back
typedef long long ll;
#define int ll
using namespace std;

const int nmax = 1000500;

int n;
int t[nmax];
void upd(int v, int s)
{
    for (int i = v; i < n; i |= i+1)
        t[i]+=s;
}
int get(int v)
{
    int s=0;
    for (int i=v; i>=0; i&=(i+1), i--)
        s+=t[i];
    return s;
}

int C = 30;
set<int> pos[30];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ___;
    cin>>___;
    while (___--)
    {
        string s, tx;
        cin>>n;
        cin>>s>>tx;
        for (int i=0; i<n; i++)
            t[i]=0;
        for (int i=0; i<C; i++)
            pos[i].clear();
        for (int i=0; i<n; i++)
        {
            pos[s[i]-'a'].insert(i);
        }
        int ans = 1e18;

        int cur_wast = 0;
        for (int i=0; i<n; i++)
        {
            int mn_add = 1e18;
            for (int j=0; j<int(tx[i]-'a'); j++)
            {
                auto it = pos[j].begin();
                if (it!=pos[j].end())
                {
                    int r = *it;
                    mn_add=min(mn_add, r-get(r));
                }
            }
//            cout<<___<<" "<<cur_wast<<" "<<mn_add<<"\n";
            ans=min(ans, cur_wast+mn_add);

            int q = tx[i]-'a';
            auto it = pos[q].begin();
            if (it == pos[q].end())
                break;
            int r = *it;
            pos[q].erase(it);
            cur_wast+=r-get(r);
            upd(r, 1);
        }

        if (ans==1e18)
            cout<<-1<<"\n";
        else
            cout<<ans<<"\n";
    }
}
/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n;
    cin>>n;

    map<int, int> tot;
    set<int> typ;

    vector<int> num[n+1], ans[n+1];
    int len[n+1];

    map<int, int> prv[n+1];
    set<int> rem[n+1];

    map<int, int> nxt[n+1];
    map<int, int> ind;

    for(int i=1; i<=n; i++)
    {
        cin>>len[i];

        map<int, int> tprv;
        set<int> trem;

        for(int j=0; j<len[i]; j++)
        {
            int x; cin>>x;

            num[i].push_back(x);
            ans[i].push_back(0);

            tot[x]++;
            typ.insert(x);

            if(tprv[x]==0)
            {
                tprv[x]=j+1;
                trem.insert(x);
            }
            else
            {
                tprv[x]=0;
                trem.erase(x);
                ans[i][j]=1;
            }
        }

        for(int x: trem)
        {
            rem[i].insert(x);
            prv[i][x]=tprv[x]-1;

            if(ind[x]==0) ind[x]=i;
            else
            {
                int y = ind[x];
                nxt[y][x]=i;
                nxt[i][x]=y;
                ind[x]=0;
            }
        }
    }

    for(int x: typ)
    {
        if(tot[x]%2==1)
        {
            cout<<"NO"<<endl;
            return;
        }
    }

    for(int i=1; i<=n; i++)
    {
        if(rem[i].size()==0) continue;

        int cur = i;
        while(1)
        {
            if(rem[cur].size()==0) break;

            int x = *rem[cur].begin();
            rem[cur].erase(x);

            int j = prv[cur][x];
            ans[cur][j]=1;

            cur=nxt[cur][x];
            rem[cur].erase(x);
        }
    }

    cout<<"YES"<<endl;

    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<len[i]; j++)
        {
            if(ans[i][j]==0) cout<<"L";
            else cout<<"R";
        }
        cout<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
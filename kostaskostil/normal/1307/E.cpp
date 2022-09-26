#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

//#define int long long
using namespace std;

int n, k;
int a[5050];
int s[5050];
int h[5050];
vector<pair<int, int> > v[5050];

void mul(long long &cur, int x)
{
    cur=(cur*x)%(1000000007);
}

pair<int, long long> ans(int l)
{
    if (v[a[l]].size()==0)
    return {0, 0};
    int cnt=0;
    long long cntx=1;
    for (int i=1; i<=n; i++)
        if (v[i].size()>0)
    {
        int x=0, y=0;
        for (int j=0; j<v[i].size(); j++)
        {
            if (v[i][j].fi<=l)
                x++;
            if (v[i][j].se>l)
                y++;
        }

        if (a[l]==i)
            if ((x==0) or (v[i][x-1].fi!=l))
                return {0, 0};

        if (a[l]!=i)
        {
            if (y>x)
                swap(x, y);
            /// x>=y
            if ((y>=1) and (x>=2))
            {
                cnt+=2;
                mul(cntx, y*(x-1));
                continue;
            }
            if (x>=1)
            {
                cnt+=1;
                mul(cntx, x+y);
                continue;
            }
        }
        else
        {
            if (x>y)
            {
                if (y>=1)
                {
                    cnt+=2;
                    mul(cntx, y);
                    continue;
                }
                if (y==0)
                {
                    cnt+=1;
                    continue;
                }
            }
            if (x<=y)
            {
                if (y>=2)
                {
                    cnt+=2;
                    mul(cntx, y-1);
                    continue;
                }
                else
                {
                    cnt++;
                    continue;
                }
            }
        }
    }
    return {cnt, cntx};
}

pair<int, long long> anyone()
{
    int cnt=0;
    long long cntx=1;
    for (int i=1; i<=n; i++)
        if (v[i].size()>0)
            cnt++, mul(cntx, v[i].size());
    return {cnt, cntx};
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=k; i++)
        cin>>s[i]>>h[i];
    for (int i=1; i<=k; i++)
    {
        int f1=0;
        int f2=0;
        int c=0;
        for (int j=1; j<=n; j++)
            if (a[j]==s[i])
        {
            c++;
            if (c==h[i])
            {
                f1=j;
                break;
            }
        }
        if (f1==0)
            continue;
        c=0;
        for (int j=n; j>=1; j--)
            if (a[j]==s[i])
        {
            c++;
            if (c==h[i])
            {
                f2=j;
                break;
            }
        }
        v[s[i]].pb(make_pair(f1,f2));
    }

    for (int i=1; i<=n; i++)
        sort(v[i].begin(), v[i].end());
    vector<pair<int, long long> > q;
    for (int i=1; i<=n; i++)
        q.pb(ans(i));//, cout<<"ans: "<<i<<" "<<q[i-1].fi<<" "<<q[i-1].se<<"\n";
    q.pb(anyone());
    int answ=0;
    for (int i=0; i<=n; i++)
        answ=max(answ, q[i].fi);
    long long res=0;
    for (int i=0; i<=n; i++)
        if (answ==q[i].fi)
            res+=q[i].se;
    if (answ==0)
        res=1;
    cout<<answ<<" "<<res%1000000007<<"\n";
    return 0;
}
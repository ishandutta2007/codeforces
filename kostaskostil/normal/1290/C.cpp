#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

//#define int long long

using namespace std;

vector<int> m[300500];
int n, k;
int a[300500];
int ans;
int p[600500];
int cnt[600500];
int cntx[600500];
bool f[600500];
bool debug=false;
int pr(int v)
{
    if (v==p[v])
        return v;
    return p[v]=pr(p[v]);
}

int delta(int i)
{
//    cout<<"delta "<<i<<"\n";
    i=pr(i);
    if (f[i])
        return cnt[i]-cntx[i];
    int j=i+k;
    if (j>2*k)
        j-=2*k;
    if (f[pr(j)])
        return cntx[i];
    return min(cntx[i], cnt[i]-cntx[i]);
}

void un(int v1, int v2, bool g)
{
    v1=pr(v1);
    v2=pr(v2);
    if (v1==v2)
        return;
    if (rand()%2)
        swap(v1, v2);
    if (!g)
    {
    ans-=delta(v1);
    ans-=delta(v2);
    if (debug)
    cout<<"delta 1="<<delta(v1)<<"\n",
    cout<<"delta 2="<<delta(v2)<<"\n";
    }
    cnt[v1]+=cnt[v2];
    cntx[v1]+=cntx[v2];
    if (f[v2])
        f[v1]=true;
    p[v2]=v1;
    if (g)
    {
        if (debug)
            cout<<"delta 1="<<delta(v1)<<"\n";
        ans+=delta(v1);
    }
}


main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    string s;
    cin>>s;
    for (int i=0; i<n; i++)
        a[i+1]=int(s[i]-'0');
    for (int i=1; i<=k; i++)
    {
        int c;
        cin>>c;
        for (int j=1; j<=c; j++)
        {
            int q;
            cin>>q;
            m[q].pb(i);
        }
    }
    for (int i=1; i<=k; i++)
        p[i]=i, cnt[i]=1, cntx[i]=1;
    for (int i=k+1; i<=2*k; i++)
        p[i]=i, cnt[i]=1, cntx[i]=0;
    ans=0;
    for (int i=1; i<=n; i++)
    {
        if (debug)
            cout<<"dbg "<<i<<"\n";
        if (m[i].size()==1)
        {
//            cout<<"DEBUG\n";
            //cout<<m[i][0]<<""\n";
//            cout<<ans<<"\n";
            ans-=delta(m[i][0]);
//            cout<<ans<<"\n";
            if (a[i]==1)
                f[pr(m[i][0])]=true;
            else
                f[pr(k+m[i][0])]=true;
            ans+=delta(m[i][0]);
        }
        if (m[i].size()==2)
        {
//            cout<<"dbg\n";
            if (a[i]==1)
            {
                un(m[i][0], m[i][1], false);
                un(m[i][0]+k, m[i][1]+k, true);
            }
            else
            {
                un(m[i][0]+k, m[i][1], false);
                un(m[i][0], m[i][1]+k, true);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
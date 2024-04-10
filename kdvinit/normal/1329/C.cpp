/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1100000;
int a[N];
int Index[N];

int h, g, n, m;

int Depth(int x)
{
    int ans = 1;
    while(x!=1)
    {
        ans++;
        x/=2;
    }
    return ans;
}

int val(int node)
{
    if(node>n) return 0;
    else return a[node];
}

int Height(int i)
{
    int l = 2*i;
    int r = 2*i+1;

    int vl = val(l);
    int vr = val(r);

    if(vl==0 && vr==0)
    {
        return 1;
    }
    else
    {
        if(vl>vr)
        {
            return Height(l)+1;
        }
        else
        {
            return Height(r)+1;
        }
    }
}

int Total_Height(int i)
{
    int ans = Depth(i) + Height(i) - 1;
    return ans;
}

int Update(int i)
{
    int l = 2*i;
    int r = 2*i+1;

    int vl = val(l);
    int vr = val(r);

    if(vl==0 && vr==0)
    {
        a[i]=0;
    }
    else
    {
        if(vl>vr)
        {
            a[i]=vl;
            Index[vl]=i;
            Update(l);
        }
        else
        {
            a[i]=vr;
            Index[vr]=i;
            Update(r);
        }
    }
}

void solve()
{
    cin>>h>>g;
    n = (1<<h)-1;
    m = (1<<g)-1;

    int b[n+1];
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        b[i]=a[i];
        Index[a[i]]=i;
    }
    sort(b+1, b+n+1);

    vector<int> Ans;

    for(int i=n; i>=1; i--)
    {
        int ind = Index[b[i]];

        int tot = Total_Height(ind);
        if(tot==g) continue;

        Ans.push_back(ind);
        Update(ind);
    }

    int sum=0;
    for(int i=1; i<=m; i++) sum+=a[i];
    cout<<sum<<endl;

    for(int i=0; i<Ans.size(); i++) cout<<Ans[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
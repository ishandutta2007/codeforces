/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int dl, dr;

int eval(vector<int> a)
{
    int n = a.size();
    int pre[n]={0};;

    int fi=-1, li=-1, cntn=0, tot=0;
    for(int i=0; i<n; i++)
    {
        if(a[i]==2 || a[i]==-2) tot++;
        pre[i]=tot;

        if(a[i]<0)
        {
            cntn++;
            if(fi==-1) fi=i;
            li=i;
        }
    }

    if(cntn%2==0)
    {
        dl=0;
        dr=0;
        return tot;
    }

    int pl=0;
    if(li!=0) pl=pre[li-1];

    int pr=tot-pre[fi];

    if(pl>pr)
    {
        dl=0;
        dr=(n-li);
        return pl;
    }
    else
    {
        dl=fi+1;
        dr=0;
        return pr;
    }
}

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int av=0, al=n, ar=0;
    for(int i=1; i<=n; i++)
    {
        if(a[i]==0) continue;

        vector<int> b;
        int j;
        for(j=i; j<=n; j++)
        {
            if(a[j]==0) break;
            b.push_back(a[j]);
        }

        int tv = eval(b);

        if(tv>av) { av=tv; al=i-1+dl; ar=n-(j-1)+dr; }

        i=j-1;
    }

    cout<<al<<" "<<ar<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
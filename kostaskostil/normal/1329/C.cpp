#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

#define int long long

using namespace std;

const int nmax=4000500;

int h, g;
int a[nmax];
vector<int> ans;

int f(int i, int l)
{
    if ((a[2*i]==0) and (a[2*i+1]==0))
        return l;
    if (a[2*i]>a[2*i+1])
        return f(2*i, l+1);
    else
        return f(2*i+1, l+1);
}

void do_(int i, bool f=true)
{
    if (f)
    ans.pb(i);
    if ((a[2*i]==0) and (a[2*i+1]==0))
        a[i]=0;
    else
    {
        if (a[2*i]>a[2*i+1])
            a[i]=a[2*i], do_(2*i, false);
        else
            a[i]=a[2*i+1], do_(2*i+1, false);
    }
}

void cut(int v, int l=1)
{
    while(f(v, l)>g)
        do_(v);

    if (l<g)
    {
        cut(2*v, l+1);
        cut(2*v+1, l+1);
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++)
    {
        cin>>h>>g;
        for (int i=1; i<(1<<(h+1)); i++)
            a[i]=0;
        for (int i=1; i<(1<<h); i++)
            cin>>a[i];
        ans.clear();
        cut(1);
        int s=0;
        for (int i=1; i<(1<<g); i++)
            s+=a[i];
        cout<<s<<"\n";
        for (int i:ans)
            cout<<i<<" ";
        cout<<"\n";
    }
}
#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define fi first
#define se second
#define pb push_back

//#define int long long
using namespace std;

int n;
int pos;
int c;
int used[20];
int g[20][20];
vector<long long> ans;
vector<int> l1, l2, a1, a2;
int cntbit(int x)
{
    if (x==0)
        return 0;
    return cntbit(x&(x-1))+1;
}
int ith(int x, int i)
{
    return (x>>i)&1;
}

void last()
{
//    cout<<c<<"in\n";
    l1.clear();
    l2.clear();
    a1.clear();
    a2.clear();
    a1.resize(1<<(pos-1));
    a2.resize(1<<(n-pos));
    for (int i=1; i<=n; i++)
    {
        if (used[i]==2)
            l1.pb(i);
        if (used[i]==0)
            l2.pb(i);
    }
    while (true)
    {
        int cx=0;
        l1.pb(c);
        for (int i=pos-2; i>=0; i--)
        {
            cx*=2;
            cx+=g[l1[i]][l1[i+1]];
        }
        l1.pop_back();
        a1[cx]++;
        if (!next_permutation(l1.begin(), l1.end()))
            break;
    }
    while (true)
    {
        int cx=0;
        l2.pb(c);
        for (int i=0; i<n-pos; i++)
        {
            cx*=2;
            cx+=g[l2[i]][l2[i+1]];
        }
        l2.pop_back();
        a2[cx]++;
        if (!next_permutation(l2.begin(), l2.end()))
            break;
    }
    for (int i=0; i<(1<<(pos-1)); i++)
        for (int j=0; j<(1<<(n-pos)); j++)
    {
//        cout<<i<<" "<<j<<" "<<a1[i]*a2[j]<<"\n";
        long long pl=a1[i];
        ans[i+(j<<(pos-1))]+=pl*a2[j];
    }
}

void pereb(int cnt, int f=1)
{
//    cout<<"OK\n";
    if (cnt==pos-1)
        last();
    else
    for (int i=f; i<=n; i++)
        if (used[i]==0)
    {
        used[i]=2;
        pereb(cnt+1, i+1);
        used[i]=0;
    }
}

main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    cin>>n;
    pos=(n+1)/2;
    ans.resize(1<<(n-1));
    for (int i=1; i<=n; i++)
    {
        string s;
        cin>>s;
        for (int j=1; j<=n; j++)
            if (s[j-1]=='1')
                g[i][j]=1;
            else
                g[i][j]=0;
    }
    for (c=1; c<=n; c++)
    {
        used[c]=1;
        pereb(0);
        used[c]=0;
    }
    for (long long i:ans)
        cout<<i<<" ";
    return 0;
}
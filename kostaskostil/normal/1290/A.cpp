#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

//#define int long long

using namespace std;

int n, k;
int a[100500];
int b[100500];
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++)
    {
        int m;
    cin>>n>>m>>k;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=m; i++)
        b[i]=max(a[i], a[i+n-m]);
    int l=1;
    int r=m;
    k=min(k, m-1);
    multiset<int> s;
    for (int i=1; i<=m-k; i++)
        s.insert(b[i]);
    int mx=*s.begin();
    for (int i=m-k+1; i<=m; i++)
    {
        s.erase(s.find(b[i-(m-k)]));
        s.insert(b[i]);
        mx=max(mx, *s.begin());
    }
    cout<<mx<<"\n";
    }

    return 0;
}
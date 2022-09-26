#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define int long long
//#define double long double

#define y0 y___0
#define y1 y___1

#define fi first
#define se second
#define pb push_back

#define timer (clock()*1.0/CLOCKS_PER_SEC)
#define e 0.000000000000000001

using namespace std;

int p[1005000];
vector<pair<int, int> > g;
int n;
int a[100500];
int cnt=0;

void added(int v1, int v2)
{
    g.pb({v1, v2});
    a[v1]++;
    a[v2]++;
    cnt++;
}

void out()
{
    cout<<cnt<<"\n";
    for (auto pa:g)
        cout<<pa.fi<<" "<<pa.se<<"\n";
    exit(0);
}
main()
{

        ios_base::sync_with_stdio();
        cin.tie(0);
        cout.tie(0);

    for (int i=0; i<100500; i++)
        p[i]=1;
    p[0]=0;
    p[1]=0;
    for (int i=2; i<100500; i++)
        if (p[i]==1)
        for (int j=2*i; j<100500; j+=i)
            p[j]=0;
    cin>>n;
    for (int i=1; i<n; i++)
        added(i, i+1);
    added(n, 1);
    for (int i=1; i<n; i++)
    {
        if (p[cnt]==1)
            out();
        if (i<n-i)
            added(i, n-i);
    }

    if (p[cnt]==1)
        out();

}
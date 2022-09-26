#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back

using namespace std;

int n;
int k;
map<int, int> m;
int a[200500];
vector<int> q;

bool check(int t)
{
    int ans=0;
    for (auto pa:m)
        ans+=pa.se/t;
    if (ans>=k)
        return true;
    return false;
}

main()
{

    cin>>n>>k;
    int x;
    int ans=0;
    int s=0;
    for (int i=1; i<=n; i++)
        cin>>a[i], m[a[i]]++;
    int l=1;
    int r=n+1;
    while (r-l>1)
    {
        int m0=(l+r)/2;
        if (check(m0))
            l=m0;
        else
            r=m0;
    }
    int qq=0;
    for (auto pa:m)
        for (int i=1; i<=pa.se/l; i++)
            {
                cout<<pa.fi<<" ";
                qq++;
                if (qq==k)
                    exit(0);
            }

    return 0;
}
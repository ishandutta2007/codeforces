#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

#define int long long

using namespace std;

int a[100500];
    int n, k;
    int s=0;

void add(int x)
{
    map<int, int> mp;
    mp[0]=1;
    for (int i=1; i<=n; i++)
        s+=mp[a[i]-x], mp[a[i]]++;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for (int i=1; i<=n; i++)
        cin>>a[i], a[i]+=a[i-1];
    if (k==1)
        add(1);
    else if (k==-1)
        add(1), add(-1);
    else
        for (int j=1; ; j*=k)
        {
            add(j);
            if (log10(abs(j))+log10(abs(k))>18.1)
                break;
        }
    cout<<s<<"\n";
}
#include <bits/stdc++.h>

#define int long long
#define pb push_back
#define fi first
#define se second

using namespace std;

pair<int,int> a[500];
int b[500];
int c[500];
int n;

bool ch(int t)
{
    int s1=0, s2=0;
    for (int i=0; i<n; i++)
        if ((t>>i)&1)
        {
            s1+=b[i];
            s2+=c[i];
        }
    return (s1!=s2);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i].fi, a[i].se=i, c[i-1]=a[i].fi;
    sort(a+1, a+n+1);
    for (int i=1; i<=n; i++)
        c[i]=a[i].se;
    for (int i=1; i<=n; i++)
        b[c[i%n+1]]=a[i].fi;
//    for (int i=0; i<n; i++)
//        cout<<c[i]<<" ";
    for (int i=1; i<=n; i++)
        cout<<b[i]<<" ";
//    for (int i=1; i<(1<<n)-1; i++)
//        if (!ch(i))
//            cout<<"-1"<<"\n", exit(0);

    return 0;
}
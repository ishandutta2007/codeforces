#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;

int a[100500];
int b[100500];
set<int> s;

main()
{
    int n; int x;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i], b[a[i]]++;
    for (int i=1; i<=n; i++)
        if (b[i]==0)
            s.insert(i);
    
    for (int i=1; i<=n; i++)
    if ((b[a[i]]>1) or (a[i]>n))
    {
        int t=*s.begin();
        b[a[i]]--;
        b[t]++;
        a[i]=t;
        s.erase(s.begin());
    }

    for (int i=1; i<=n; i++)
        cout<<a[i]<<" ";
    return 0;
}
#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

int n;

set<int> findset(int k)
{
    set<int> res;
    for (int i=1; i<=n; i++)
        if (i%k != 1)
            res.insert(i);
    return res;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    if (n<=3)
    {
        cout<<0<<"\n";
        return 0;
    }

    int k=1e9;
    set<int> res;
    for (int i=2; i<=n; i++)
    {
        auto s=findset(i);
        if (int(s.size()) - i > int(res.size()) - k)
        {
            res=s;
            k=i;
        }
    }

//    cout<<k<<"\n";
//    for (int i:res)
//        cout<<i<<" ";
//    cout<<endl;

    while (res.size() >= k)
    {
        cout<<k<<" ";
        for (int i=0; i<k; i++)
            cout<<*res.begin()<<" ", res.erase(res.begin());
        cout<<endl;

        int x;
        cin>>x;
        for (int i=0; i<k; i++)
        {
            if (x%k!=1)
                res.insert(x);
            x=(x%n)+1;
        }
    }
    cout<<0<<endl;
    return 0;
}
#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;

vector<int> p, ans;

main()
{
    int n;
    cin>>n;
    p.push_back(2);
    for (int i=3; i<=n; i++)
    {
        int c=1;
        for (int j:p)
            if (i%j==0)
                c=0;
        if (c==1)
            p.push_back(i);
    }


    for (int i:p)
    {
        int c=i;
        while (c<=n)
        {
            ans.push_back(c);
            c*=i;
        }
    }
    cout<<ans.size()<<"\n";
    for (int i:ans)
        cout<<i<<" ";

    return 0;
}
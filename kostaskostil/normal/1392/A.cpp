#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
#define int ll

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int qqq;
    cin>>qqq;
    for (int iii=0; iii<qqq; iii++)
    {
        int n, k;
        cin>>n;
        vector<int> v(n);
        for (int& i:v) cin>>i;
        bool ok=true;
        for (int i=1; i<n; i++)
            if (v[i]!=v[0])
                ok=false;
        if (ok)
            cout<<n<<"\n";
        else cout<<"1\n";
    }
    return 0;
}
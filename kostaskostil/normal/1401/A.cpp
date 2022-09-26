#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
#define int long long

main()
{
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++)
    {
        int n, k;
        cin>>n>>k;
        if (n>=k)
        {
            if ((n-k)%2==0) cout<<"0\n";
            else cout<<"1\n";
        }
        else
        {
            cout<<k-n<<"\n";
        }
    }

    return 0;
}
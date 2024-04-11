#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
#define int ll

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, l = 0;
    cin>>n;
    string s = "blue";
    while (n--)
    {
        string t;
        cin>>t;
        if (t=="lock")
            l=1;
        else if (t=="unlock")
            l=0;
        else if (l==0)
            s = t;
    }
    cout<<s<<"\n";
}
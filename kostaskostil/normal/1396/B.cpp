#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

const int nmax=1e6+100;
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
        int n;
        cin>>n;
        vector<int> v(n);
        for (int& i:v) cin>>i;
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        int s=0;
        for (int i=1; i<n; i++)
            s+=v[i];

        bool ok;
        if (v[0] > s)
            ok=true;
        else
            ok = (v[0] + s)%2;
        if (ok)
            cout<<"T\n";
        else
            cout<<"HL\n";

    }
}
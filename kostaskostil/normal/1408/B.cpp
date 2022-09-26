#include "bits/stdc++.h"

#define fi first
#define se second
#define pb push_back

using namespace std;

#define nmax 500500
typedef long long ll;
#define int ll

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for (int _=0; _<n; _++)
    {
        int n, k;
        cin>>n>>k;
        vector<int> v(n);
        for (int& i:v)
            cin>>i;
        int m=0;
        for (int i=0; i+1<n; i++)
            if (v[i]!=v[i+1])
                m++;
        if (k==1)
        {
            if (m==0)
                cout<<1<<"\n";
            else
                cout<<-1<<"\n";
        }
        else
            cout<<max(1ll, (m+k-2)/(k-1) )<<"\n";
    }

}
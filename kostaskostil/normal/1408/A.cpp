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
        int n;
        cin>>n;
        vector<int> a(n), b(n), c(n);
        for (int& i:a)
            cin>>i;
        for (int& i:b)
            cin>>i;
        for (int& i:c)
            cin>>i;
        int q=a[0];
        cout<<a[0]<<" ";
        for (int i=1; i<n; i++)
        {
            if ((a[i]!=q) and (a[i]!=a[0]))
                q=a[i];
            else
            if ((b[i]!=q) and (b[i]!=a[0]))
                q=b[i];
            else
                q=c[i];
            cout<<q<<" ";
        }
        cout<<"\n";
    }

}
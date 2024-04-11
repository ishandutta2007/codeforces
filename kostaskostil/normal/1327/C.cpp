#include <bits\stdc++.h>
#define pb push_back
#define fi first
#define se second
#define int long long

using namespace std;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    cout<<n-1+m-1+n*(m-1)+n-1<<"\n";
    for (int i=1; i<n; i++)
        cout<<"D";
    for (int i=1; i<m; i++)
        cout<<"L";
    for (int i=1; i<=n; i++)
    {
        if (i%2==1)
        {
            for (int j=1; j<m; j++)
                cout<<"R";
        }
        else
        {
            for (int j=1; j<m; j++)
                cout<<"L";
        }
        if (i!=n)
            cout<<"U";
    }
    return 0;
}
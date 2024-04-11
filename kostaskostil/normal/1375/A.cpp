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
        int n;
        cin>>n;
        vector<int> v(n);
        for (int& i:v)
            cin>>i;
        for (int i=0; i<n; i++)
        {
            if (i%2==0)
            cout<<abs(v[i])<<" ";
            else cout<<-abs(v[i])<<" ";
        }
        cout<<"\n";
    }
}
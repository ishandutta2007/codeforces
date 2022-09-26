#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

typedef long long ll;
#define int ll

using namespace std;

const int nmax = 1e6 + 100;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int qqq;
    cin>>qqq;
    while (qqq--)
    {
        int n;
        cin>>n;
        int x;
        for (int i=0; i<n; i++)
            cin>>x;
            cout<<6*(n/2)<<"\n";
        for (int i=0; i<n/2; i++)

        {
            int x = 2*i+1;
            int y = 2*i+2;
            cout<<"1 "<<x<<" "<<y<<"\n";
            cout<<"2 "<<x<<" "<<y<<"\n";
            cout<<"1 "<<x<<" "<<y<<"\n";
            cout<<"1 "<<x<<" "<<y<<"\n";
            cout<<"2 "<<x<<" "<<y<<"\n";
            cout<<"1 "<<x<<" "<<y<<"\n";
        }
    }
}
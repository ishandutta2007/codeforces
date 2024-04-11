#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

const int nmax=200500;
int c[nmax];
int t[nmax];


main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tx;
    cin>>tx;
    for (int j=1; j<=tx; j++)
    {
        int n;
        cin>>n;
        for (int i=1; i<=n; i++)
            cin>>t[i];
        t[n+1]=t[1];
        bool f=false;
        for (int i=1; i<=n; i++)
            if (t[i]!=t[i+1])
                f=true;
        if (!f)
        {
            cout<<1<<"\n";
            for (int i=1; i<=n; i++)
                cout<<1<<" ";
            cout<<"\n";
            continue;
        }

        int x=-1;
        for (int i=1; i<=n; i++)
            if (t[i]==t[i+1])
                x=i;

        if ((x==-1) and (n%2==1))
        {
            cout<<3<<"\n";
            for (int i=1; i<n; i++)
                cout<<(i%2)+1<<" ";
            cout<<3<<"\n";
        }
        else
        {
            if (n%2==0)
            {
                cout<<2<<"\n";
                for (int i=1;i<=n; i++)
                    cout<<i%2+1<<" ";
                    cout<<"\n";
            }
            else
            {
                cout<<2<<"\n";
                for (int i=1; i<=n; i++)
                cout<<((i+(i>x))%2)+1<<" ";
                cout<<"\n";

            }
        }
    }
}
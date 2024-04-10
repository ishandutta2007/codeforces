#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include<math.h>
using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define mp make_pair
#define double long double
#define fi first
#define se second
#define int long long

typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set; // find_by_order(x) <-returns x-th element   order_of_key(x) <- returns order of element x

const int z=1234567890;

main()
{
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout.setf(ios::fixed);


    int n;
    cin>>n;
    vector <int> X (n+1);
    int ile_ujemnych=0;
    int ile_zer=0;
    int ile_dodatnich=0;

    for (int i=1; i<=n; i++)
    {
        cin>>X[i];
        if(X[i]>0)
            ile_dodatnich++;
        if(X[i]<0)
            ile_ujemnych++;
        if(X[i]==0)
            ile_zer++;
    }


    if(ile_zer==n  || (ile_zer==(n-1) && ile_ujemnych==1))
    {
        for (int i=2; i<=n; i++)
            cout <<1<<" "<<i<<" "<<1<<endl;
        return 0;
    }
///////////
    if((ile_ujemnych%2)==1)
    {
        int mini=-z;
        int k=-1;

        for (int i=1; i<=n; i++)
        {
            if (X[i]<0 && X[i]>mini)
            {
                mini=X[i];
                k=i;
            }
        }

        for (int i=1; i<=n; i++)
        {
            if(X[i]==0)
            {
                cout <<1<<" "<<i<<" "<<k<<endl;
                X[i]=z;
            }
        }
        X[k]=z;
        cout <<2<<" "<<k<<endl;

        k=-1;

        for (int i=1; i<=n; i++)
        {
            if(k==-1 && X[i]!=z)
                k=i;

            if(k!=i && X[i]!=z)
                cout <<1<<" "<<i<<" "<<k<<endl;

        }
        return 0;
    }

////////////////
    if(ile_zer>0)
    {
        int k=-1;

        for (int i=1; i<=n; i++)
        {
            if (X[i]==0 )
                k=i;
        }

        for (int i=1; i<=n; i++)
        {
            if (X[i]==0 && i!=k )
                cout <<1<<" "<<i<<" "<<k<<endl;
        }

        cout <<2<<" "<<k<<endl;

    }


    int  k=-1;

    for (int i=1; i<=n; i++)
    {
        if(k==-1 && X[i]!=0)
            k=i;

        if(k!=i && X[i]!=0)
            cout <<1<<" "<<i<<" "<<k<<endl;
    }
    return 0;
    }
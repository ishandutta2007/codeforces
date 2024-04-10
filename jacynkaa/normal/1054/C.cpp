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

typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set; // find_by_order(x) <-returns x-th element   order_of_key(x) <- returns order of element x

main()
{
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout.setf(ios::fixed);


    int n;
    cin>>n;
    vector <int> R (n);
    vector <int> L (n);
    vector <int> ODP (n);
    for (int i=0;i<n;i++)
    cin>>L[i];

      for (int i=0;i<n;i++)
    cin>>R[i];

    for (int i=0; i<n; i++)
        ODP[i]=n-(L[i]+R[i]);

    for (int i=0; i<n; i++)
    {
        int l=0;
        int r=0;
        for (int j=0; j<i; j++)
            if(ODP[j]>ODP[i])
                l++;
        for (int j=i+1; j<n; j++)
            if(ODP[j]>ODP[i])
                r++;

        if(r!= R[i] || l!=L[i])
        {
            cout <<"NO"<<endl;
            return 0;
        }
    }

    cout <<"YES"<<endl;
    for (int i=0; i<n; i++)
        cout <<ODP[i]<<" ";
    cout <<endl;
}
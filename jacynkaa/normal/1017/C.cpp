#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define mp make_pair
#define int long long

typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set; // find_by_order(x) <-returns x-th element   order_of_key(x) <- returns order of element x

main()
{
    int n;
    cin>>n;

    int x=1;
        while (x*x<n)
        x++;

    vector <int> X;
    for (int i=1; i<=n; i++)
        X.push_back(i);

    int wskaznik=0;

    while (wskaznik<=2*n)
    {
        int q=wskaznik;
        wskaznik+=x;
        for (int i=wskaznik-1; i>=q; i--)
            if(i<n)
                cout <<X[i]<<" ";

    }
}
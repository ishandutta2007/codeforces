#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define mp make_pair

typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set; // find_by_order(x) <-returns x-th element   order_of_key(x) <- returns order of element x


main()
{
    ios_base::sync_with_stdio(false);

    string c;

    cin>>c;
     int q=c.size();

    for (int i=0;i<q;i++)
    c.push_back(c[i]);


    int mak=1;
    int odp=1;

    for (int i=1; i<c.size(); i++)
        if(c[i]!=c[i-1])
        {
        odp++;
            mak=max(odp, mak);

        }
        else
            odp=1;

    cout <<min(q,mak)<<endl;

    }
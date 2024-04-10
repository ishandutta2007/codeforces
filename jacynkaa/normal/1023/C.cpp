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
    ios_base::sync_with_stdio(false);

    int n,k;
    cin>>n>>k;
    string c;
    cin>>c;
    int a=n-k;
    a=a/2;

    int o=0;
    int z=0;
    int ile_otwartych=0;
   // cout <<c<<endl;

    for (int i=0; i<n; i++)
    {
        if(c[i]=='(')
        {
            if(o==a)
            {
                ile_otwartych++;
                cout <<c[i];
            }
            else
            {
                o++;
            }

        }
        else
        {
            if(ile_otwartych!=0)
            {
                ile_otwartych--;
                cout <<c[i];
            }
        }
    }
    cout <<endl;
    }
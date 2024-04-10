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

main()
{
    ios_base::sync_with_stdio(false);
    cout.precision(10);


    int q;
    cin>>q;

    for (int i=0; i<q; i++)
    {
        int n,m,k;
        cin>>n>>m>>k;



        int diag=min(n,m);
        int normal =max(n,m)-min(n,m);

        int normalp=normal%2;

        diag=diag+normal-normalp;
        normal=normalp;

      //  cout <<diag<<" "<<normal<<endl;

        if(normal+diag>k)
        {
            cout <<-1<<endl;
        }
        else
        {

            if(normal>0)
                cout <<k-normal<<endl;
            else
            {
                k=k-diag;
                if((k%2)==0)
                    cout <<k+diag<<endl;
                else
                    cout <<k+diag-2<<endl;
            }

        }

    }
}
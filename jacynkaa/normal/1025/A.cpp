#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define mp make_pair

typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set; // find_by_order(x) <-returns x-th element   order_of_key(x) <- returns order of element x

main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;
    string c;
    cin>>c;

    map<int, int > M;

if(n==1)
{
   cout <<"YES"<<endl;
            return 0;
            }
    for (int i=0; i<c.size(); i++)
    {
        M[c[i]]++;
        if(M[c[i]]==2)
        {
            cout <<"YES"<<endl;
            return 0;
        }

    }
         cout <<"NO"<<endl;

    }
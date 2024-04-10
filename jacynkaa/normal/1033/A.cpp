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


bool czek (int a, int b, int c)
{
    if(a>b &&c>b)
        return true;
    if(a<b && c<b)
        return true;
               return false;
}

main()
{
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout.setf(ios::fixed);


    int n;
    cin>>n;

    int a1,a2,b1,b2,c1,c2;
    cin>>a1>>a2>>b1>>b2>>c1>>c2;
    if(czek(b1,a1,c1) && czek(b2,a2,c2))
        cout<<"YES"<<endl;
    else
        cout <<"NO"<<endl;
}
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

int nwd (int a, int b)
{
    while (b!=0)
    {
        int c=b;
        b=a%b;
        a=c;
    }
    return a;
}


main()
{
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout.setf(ios::fixed);

       // cout <<nwd(4,6)<<endl;


    int a,b,x,y;
    cin>>a>>b>>x>>y;

int q=nwd(x,y);
    x=x/q;
    y=y/q;
   // cout <<x<<" "<<y<<endl;
    cout <<min(a/x,b/y)<<endl;
}
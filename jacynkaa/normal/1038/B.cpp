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
    cout.setf(ios::fixed);

    int n;
    cin>>n;

    int suma=n*(n+1)/2;

    if(n<3)
    {
        cout <<"No"<<endl;
        return 0;
    }

    cout <<"Yes"<<endl;
    int znaleziony=-1;

    for (int i=2; i<=n; i++)
        if((suma%i)==0)
        {
            znaleziony=i;
        }

    cout <<1<<" "<<znaleziony<<endl;
    cout <<n-1<<" ";

    for (int i=1; i<=n; i++)
        if(i!=znaleziony)
            cout <<i<<" ";
    cout <<endl;

}
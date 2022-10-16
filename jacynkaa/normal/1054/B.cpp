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

    unordered_map<int, int> M;
    int n;
    cin>>n;
int     ile_znalezionych=0;
    for (int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        if(M[a]==0)
        {
            M[a]=1;
            ile_znalezionych++;
        }
        if(a>=ile_znalezionych)
        {
            cout <<i+1<<endl;
            return 0;
        }
    }
    cout <<-1<<endl;
}
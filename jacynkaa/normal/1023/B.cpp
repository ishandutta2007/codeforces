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
    int a=min(n,k-1);
    int b=k-a;

    int c=a-b+1;
    if(c>1)
    cout <<c/2<<endl;
    else
    cout<<0<<endl;
    }
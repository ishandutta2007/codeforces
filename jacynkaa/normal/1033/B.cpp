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


bool sprawdz(int a)
{
    for (int i=2; i*i<=a; i++)
        if((a%i)==0)
            return false;
    return true;
}

main()
{
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout.setf(ios::fixed);
int t;
cin>>t;
while(t--)
{
    int a,b;
    cin>>a>>b;


    if((a-b)==1 &&sprawdz(a+b))
    cout <<"YES"<<endl;
    else
    cout <<"NO"<<endl;
    }
    }
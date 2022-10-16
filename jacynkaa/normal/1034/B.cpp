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

void akcja()
{

    int n,m;
    cin>>n>>m;
    int a=max(n,m);
    n=min(n,m);
    m=a;

    if(n==1)
    {
        int x=m%6;

        if(x==0)
            cout <<m<<endl;
        if(x==1)
            cout <<m-1<<endl;
        if(x==2)
            cout<<m-2<<endl;
        if(x==3)
            cout <<m-3<<endl;
        if(x==4)
            cout <<m-2<<endl;
        if(x==5)
            cout <<m-1<<endl;
        return  ;
    }

    if(((n%2==0)&& n!=2) || (m%2==0 && m!=2))
    {
        cout <<n*m<<endl;
        return ;
    }

    if((n*m)%2==1)
    {

        cout <<n*m-1<<endl;
        return ;
    }

    if(n==2 && m==2)
    {
        cout <<0<<endl;
        return;
    }

    if(n==2 &&( m==3 || m==7))
    {
    cout <<n*m-2<<endl;
    return ;
    }

    cout <<n*m<<endl;


}

main()
{


    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout.setf(ios::fixed);
    akcja();
}
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

    bool nieujemny=false;
    bool niedodatni=false;




    vector <int> A(n);

    for (int i=0; i<n; i++)
        cin>>A[i];


    int najmniejszy=abs(A[0]);
    int suma=0;

    for (int i=0; i<n; i++)
    {
        int a;
        a=A[i];
        if(a>=0)
            nieujemny=true;
        if(a<=0)
            niedodatni=true;
        suma+=abs(a);
        najmniejszy=min(abs(a), najmniejszy);
    }

    if(n==1)
    {
        cout <<A[0]<<endl;
        return 0;
    }

    if(niedodatni==true && nieujemny==true)
        cout <<suma<<endl;
    else
        cout <<suma-2*najmniejszy<<endl;
}
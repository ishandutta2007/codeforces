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



    int sum=0;


    int n;
    cin>>n;
    vector <int> A(n);

    for (int i=0; i<n; i++)
    {
        cin>>A[i];
        sum+=A[i];
    }

    int m;
    cin>>m;
vector <int> B(m);
    for (int i=0; i<m; i++)
    {
        cin>>B[i];
        sum-=B[i];
    }

    if(sum!=0)
    {
        cout <<-1;
        return 0;
    }

    int wskaznik1=0;
    int wskaznik2=0;
    int odp=0;

    while (wskaznik1!=n || wskaznik2!=m)
    {
        if(sum>=0)
        {
            sum-=B[wskaznik2];
            wskaznik2++;
        }
        else
        {
            sum+=A[wskaznik1];
            wskaznik1++;
        }
        if(sum==0)
            odp++;
    }
    cout <<odp<<endl;
}
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
    int n;
    cin>>n;
    vector <int> B (n);

    for (int i=0; i<n; i++)
        cin>>B[i];

    bool case1=true;

    for (int i=0; i <n; i++)
    {
        if(B[i]!=0)
            case1=false;
    }

    if(case1==true)
    {
        cout<< "YES"<<endl;
        for (int i=0; i<n; i++)
            cout <<1<<" ";
        cout <<endl;
        return 0;
    }
    reverse(B.begin(), B.end());


    bool case2=true;

    for (int i=0; i<n; i++)
    {
        if(B[i]!=B[0])
            case2=false;
    }

    if(case2==true)
    {
        cout <<"NO"<<endl;
        return 0;
    }

    int mak=-1;
    int dobry;
    vector <int> odp (n);

    for (int i=0; i<n; i++)
        mak=max(mak,B[i]);

    for (int i=0; i<n; i++)
        if(B[i]==mak && B[(i+1)%n]!=mak)
            dobry=i;

    odp[dobry]=B[dobry];

    if(B[(dobry+1)%n]==0)
        odp[(dobry+1)%n]=2*odp[dobry];
    else
        odp[(dobry+1)%n]=odp[dobry]+B[(dobry+1)%n];

    for (int i=1; i<n-1; i++)
        odp[(dobry+i+1)%n]=odp[(dobry+i)%n]+B[(dobry+i+1)%n];

    cout <<"YES"<<endl;
    reverse(odp.begin(), odp.end());
    for (int i=0; i<n; i++)
        cout <<odp[i]<<" ";

    cout <<endl;
}
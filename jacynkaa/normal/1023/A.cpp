#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

//#define endl "\n"
#define mp make_pair

typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set; // find_by_order(x) <-returns x-th element   order_of_key(x) <- returns order of element x

main()
{
    ios_base::sync_with_stdio(false);

    string s, t;
    int n, m;
    cin>>n>>m>>s>>t;

    int czy_jest=-1;


    for (int i=0; i<n; i++)
        if(s[i]=='*')
            czy_jest=i;

    if(czy_jest==-1)
    {
        if(s==t)
            cout<<"YES"<<endl;
        else
            cout <<"NO"<<endl;
        return 0;
    }

    if(m<n-1)
    {
        cout <<"NO"<<endl;
        return 0;
    }

bool     czy_ok=true;

    for (int i=0; i<czy_jest; i++)
        if(s[i]!=t[i])
            czy_ok=false;

    for (int i=1; i<n-czy_jest; i++)
        if(s[n-i]!=t[m-i])
            czy_ok=false;

    if(czy_ok==true)
        cout <<"YES"<<endl;
    else
        cout <<"NO"<<endl;

}
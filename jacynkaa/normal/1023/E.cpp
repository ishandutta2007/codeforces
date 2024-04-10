#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define mp make_pair
#define fi first
#define se second

typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set; // find_by_order(x) <-returns x-th element   order_of_key(x) <- returns order of element x

int n;

string jed;
string dwa;

void do_pierwszego (pair<int, int> X, int k)
{
    if(k==n)
        return;

    auto C=X;
    C.se++;
    cout <<"? "<<C.fi<<" "<<C.se<<" "<<n<<" "<<n<<endl;

    string q;
    cin>>q;

    if(q[0]=='Y')
    {
        jed.push_back('R');
        do_pierwszego(C, k+1);
    }
    else
    {
        X.fi++;
        jed.push_back('D');
        do_pierwszego(X, k+1);
    }
}

void do_drugiego (pair<int, int> X, int k)
{
    if(k==n)
        return;

    auto C=X;
    C.fi--;
    cout <<"? "<<1<<" "<<1<<" "<<C.fi<<" "<<C.se<<endl;

    string q;
    cin>>q;

    if(q[0]=='Y')
    {
        dwa.push_back('D');
        do_drugiego(C, k+1);
    }
    else
    {
        X.se--;
        dwa.push_back('R');
        do_drugiego(X, k+1);
    }
}

main()
{
    cin>>n;
    cout <<endl;
    auto J=mp(1,1);
    auto D=mp(n,n);
    do_pierwszego(J,1);
    do_drugiego(D,1);
    reverse(dwa.begin(), dwa.end());

    for (int i=0;i<n-1;i++)
    jed.push_back(dwa[i]);

    cout <<"! "<<jed<<endl;
}
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

const int z=1234567890;
main()
{
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout.setf(ios::fixed);

    int tab[7];

    for (int i=0; i<7; i++)
        tab[i]=z;

    int n;
    cin>>n;


    for (int i=0; i<n; i++)
    {
        int a;
        string c;
        cin>>a>>c;

        vector <char> x;

        for (int j=0; j<c.size(); j++)
            x.push_back(c[j]);

        sort(x.begin(), x.end());

        if(x.size()==1)
        {
            if(x[0]=='A')
                tab[0]=min(tab[0],a);
            if(x[0]=='B')
                tab[1]=min(tab[1],a);
            if(x[0]=='C')
                tab[2]=min(tab[2],a);
        }

        if(x.size()==2)
        {
            if(x[0]=='A' && x[1]=='B')
                tab[3]=min(tab[3],a);
            if(x[0]=='A' && x[1]=='C')
                tab[4]=min(tab[4],a);
            if(x[0]=='B' && x[1]=='C')
                tab[5]=min(tab[5],a);
        }
        if(x.size()==3)
            tab[6]=min(tab[6], a);
    }
    int q=min(tab[0]+tab[1]+tab[2], tab[0]+tab[5]);
    q=min(q,tab[2]+ tab[3]);
    q=min(q, tab[1]+tab[4]);
    q=min(q, tab[6]);
    q=min(q, tab[3]+tab[4]);
    q=min(q, tab[4]+tab[5]);
    q=min(q, tab[5]+tab[3]);

    if(q==z)
        cout <<-1<<endl;
    else
        cout<<q<<endl;
}
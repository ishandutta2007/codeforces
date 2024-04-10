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

    int n,m;
    cin>>n>>m;

    int czy_juz=-1;
    int pierwszy=-1;
    int ostatni=-1;
    int kolumna=-1;

    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            char c;
            cin>>c;

            if(c=='B' && czy_juz==-1)
            {
                pierwszy=j;
                kolumna=i;
                czy_juz=0;
            }

            if(c=='B')
                ostatni=j;
        }

        cout <<kolumna+(ostatni-pierwszy)/2<<" "<<(ostatni+pierwszy)/2<<endl;
}
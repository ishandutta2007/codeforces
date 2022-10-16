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



vector <int> suma_odleglosci;
vector <int> suma_dlugosci_wiatro;

main()
{
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout.setf(ios::fixed);


    int n,h;
    cin>>n>>h;


    int poprzedni=-1;

    for (int i=0; i<n; i++)
    {
        int a, b;
        cin>>a>>b;
        suma_dlugosci_wiatro.push_back(b-a);
        if(i!=0)
            suma_odleglosci.push_back(a-poprzedni);
        else
            suma_odleglosci.push_back(0);
        poprzedni=b;
    }

   // for (int i=0; i<n; i++)
     //   cout <<i<<": "<<suma_dlugosci_wiatro[i]<<" "<<suma_odleglosci[i]<<endl;

    for (int i=1; i<n; i++)

    {
        suma_dlugosci_wiatro[i]+=suma_dlugosci_wiatro[i-1];
        suma_odleglosci[i]+=suma_odleglosci[i-1];
    }




    int odp=0;

    for (int i=0; i<n; i++)
    {

        //cout <<suma_dlugosci_wiatro[i]<<" "<<suma_odleglosci[i]<<endl;

        auto x= upper_bound(suma_odleglosci.begin(), suma_odleglosci.end(), suma_odleglosci[i]+h-1);
        x--;
        int c=x-suma_odleglosci.begin();

        //cout <<c<<endl;

        int q=h+suma_dlugosci_wiatro[c];

        int xx=suma_odleglosci[n-1];
        if(i>0)
            xx-=suma_odleglosci[i-1];
        if(xx<h)
            q=h+suma_dlugosci_wiatro[n-1];

        if(i>0)
            q-=suma_dlugosci_wiatro[i-1];
        odp=max(odp, q);
    }
    cout <<odp<<endl;
}
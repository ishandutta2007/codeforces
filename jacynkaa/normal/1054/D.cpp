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

int pot [31];

void pre()
{
    pot[0]=1;
    for (int i=1; i<31; i++)
        pot[i]=pot[i-1]*2;
}

int po_dwa (int a)
{
    return a*(a-1)/2;
}
main()
{
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout.setf(ios::fixed);

    int ile_nie_moze=0;
    int n,k;
    cin>>n>>k;
    pre();


    unordered_map<int, int> M;

    int suma=0;
    vector <int> sprawdz ;
    M[pot[k]-1]=1;

    for (int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        suma=suma^a;
      //  cout <<pot[k]<<endl;
      //  cout <<suma<<" "<<pot[k]-1-suma<<endl;
        M[max(suma, pot[k]-1-suma)]++;
        sprawdz.push_back(max(suma, pot[k]-1-suma));
    }

    for (int i=0; i<n; i++)
    {
        int a=M[sprawdz[i]];
        if(a==0)
            continue;

       // cout <<sprawdz[i]<<" "<<a<<endl;
        int b=a/2;
        int c=a-b;
        ile_nie_moze+=(po_dwa(b)+po_dwa(c));
        M[sprawdz[i]]=0;
    }
    cout <<n*(n+1)/2-ile_nie_moze<<endl;
}
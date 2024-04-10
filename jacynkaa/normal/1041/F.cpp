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

int odp=2;

int sprawdzanie (vector <int> &A, vector <int> &B, int a)
{
    unordered_map<int,int> X;

    //cout <<a<<":: "<<endl;

    for (int i=0; i<A.size(); i++)
    {
        int s=A[i]%(2*a);
       // cout <<s<<endl;
        X[s]++;
        odp=max(odp, X[s]);
    }

    for (int i=0; i<B.size(); i++)
    {
        int s=(B[i]+a)%(2*a);
       // cout <<s<<endl;
        X[s]++;
        odp=max(odp, X[s]);
    }
}

int tab [32];
main()
{
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout.setf(ios::fixed);

    tab[0]=1;
    for (int i=1; i<32; i++)
        tab[i]=tab[i-1]*2;



    int n,y1;
    cin>>n>>y1;
    vector <int> A(n);
    for (int i=0; i<n; i++)
        cin>>A[i];

    int m,y2;
    cin>>m>>y2;
    vector <int> B(m);
    for (int i=0; i<m; i++)
        cin>>B[i];

    for (int i=0; i<32; i++)
        sprawdzanie(A,B, tab[i]);

    cout <<odp<<endl;
}
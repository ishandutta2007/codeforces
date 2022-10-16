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

vector <int> P;

int mak=4e3;

void akcja(int a)
{
    for(int i=2; i<a; i++)
        if((a%i)==0)
            return ;

    P.push_back(a);
    return;
}
void prr()
{
    for (int i=2; i<mak; i++)
        akcja(i);
}



int odp=-1;
unordered_map<int, int> M;

void faktor (int x)
{
    for (int i=0; i<P.size(); i++)
    {
        if((x%P[i])==0)
        {
            M[P[i]]++;
            odp=max(odp, M[P[i]]);
        }

        while ((x%P[i])==0)
            x=x/P[i];
    }

    if(x>1)
    {
        M[x]++;
        odp=max(odp, M[x]);
    }

}


main()
{
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout.setf(ios::fixed);

    prr();
    int n;
    cin>>n;

    vector<int> X(n);
    int g=0;

     for (int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        X[i]=a;
        if(i==0)
        g=a;
        else
        g=__gcd(g,a);
    }

    for (int i=0; i<n; i++)

        faktor(X[i]/g);

    if(odp<1)
        cout <<-1<<endl;
    else
        cout <<n-odp<<endl;
}
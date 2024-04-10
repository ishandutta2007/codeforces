#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define mp make_pair


typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set; // find_by_order(x) <-returns x-th element   order_of_key(x) <- returns order of element x


const int stala=4100;
vector <int> wartosci (stala) ;
vector <int> ile_danego_typu (stala);
vector <vector <int> >odp (stala, vector <int> (110));
vector <int> W;
int n,m,q;
int mod=1;



int wartosc (string c)
{
    int x=0;
    for (int i=0; i<c.size(); i++)
    {
        x=x*2;
        x+=(c[i]-'0');
    }
    return x;
}

int val (int x)
{
    int q=W.size()-1;
    int suma=0;

    while (x>0)
    {
        if((x%2)==1)
            suma+=W[q];
        x=x/2;
        q--;

    }
    return suma;
}

void wczytywanie ()
{
    cin>>n>>m>>q;
    W.resize(n);
    for (int i=0; i<n; i++)
        cin>>W[i];
        mod=1<<(n);
        mod--;


    for (int i=0; i<m; i++)
    {
        string c;
        cin>>c;
        ile_danego_typu[wartosc(c)]++;
    }

}

void pre()
{
    for (int i=0; i<=mod; i++)
        wartosci[i]=val(i);

       // cout <<mod<<endl;

    for (int i=0; i<=mod; i++)
    {
        for (int j=0; j<=mod; j++)
        {
      //  cout <<i<<" "<<j<<" "<<(i^j)<<" "<<((i^j)^mod)<<endl;
            int a=min(wartosci[((i^j)^mod)], 101);
            odp[i][a]+=ile_danego_typu[j];
        }

        for (int j=1; j<101; j++)
            odp[i][j]+=odp[i][j-1];
    }
}

main()
{
    ios_base::sync_with_stdio(false);
    wczytywanie();
    pre();


    for (int i=0; i<q; i++)
    {
        string c;
        cin>>c;
        int x=wartosc(c);
        int a;
        cin>>a;
        cout <<odp[x][a]<<endl;
    }
}
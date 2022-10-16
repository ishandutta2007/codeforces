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

struct drzewo
{
    vector <int> D;
    int rozmiar;

    void buduj (int a)
    {
        rozmiar=1;
        while (a>rozmiar)
            rozmiar=rozmiar*2;
        D.resize(rozmiar*2,0);
    }

    void change (int q) //change values in tree on interval <0,p>
    {
        int p=rozmiar;
        q+=rozmiar;

        while (p<=q)
        {
            if(p%2==1)
            {
                D[p]++;
                p++;
            }
            if(q%2==0)
            {
                D[q]++;
                q--;
            }
            p=p/2;
            q=q/2;
        }
    }

    int znajdz (int q)
    {
        int odp=0;
        q=q+rozmiar;
        while(q>0)
        {
            odp+=D[q];
            q=q/2;
        }
        return odp;
    }
};

struct trojka
{
    int pozycja;
    int numer;
    int zapytanie; //1 dodaje 0 pytam;

    void wypisz()
    {
    cout <<pozycja<<" "<<numer<<" "<<zapytanie<<endl;
    }

};

bool operator< (trojka a, trojka b)
{
    if(a.numer==b.numer)
        return a.zapytanie<b.zapytanie;
    return a.numer<b.numer;
}

main()
{
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout.setf(ios::fixed);

    int n,t;
    cin>>n>>t;
    vector <int> X(n+1,0);

    for (int i=1; i<=n; i++)
        cin>>X[i];

    for (int i=1; i<=n; i++)
        X[i]+=X[i-1];

    vector <trojka> T;
    for (int i=0; i<=n; i++)
    {
        trojka x;
        x.pozycja=i;
        x.numer=X[i];
        x.zapytanie=1;
        T.push_back(x);
        x.numer+=t;
        x.zapytanie=0;
        T.push_back(x);
    }

    sort(T.begin(), T.end());

    drzewo Q;
    Q.buduj(n+3);
    int odp=0;

    for (int i=0; i<T.size(); i++)
    {
    //T[i].wypisz();
        if(T[i].zapytanie==0)
            odp+=Q.znajdz(T[i].pozycja);
        else
            Q.change(T[i].pozycja-1);
    }
    cout <<odp<<endl;
}
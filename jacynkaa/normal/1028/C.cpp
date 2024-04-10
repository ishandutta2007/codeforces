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


vector <pair<int, int > > L;
vector <pair<int, int > >P;
int n;


bool sprawdzenie (pair<int, int> x )
{
    int licznik=0;
    for (int i=0; i<n; i++)
        if(L[i].fi<=x.fi && L[i].se <=x.se && P[i].fi>=x.fi && P[i].se>=x.se)
            licznik++;
    if(licznik>=(n-1))
        return true;
        return false;
}

vector <int> mozliwe_X;
vector <int> mozliwe_y;

void akcja1(vector<pair<int, int> > &L)
{

    vector <int> Q;
    for (int i=0; i<n; i++)
        Q.push_back(L[i].fi);

    sort(Q.begin(), Q.end());
    mozliwe_X.push_back(Q[Q.size()-1]);
    mozliwe_X.push_back(Q[Q.size()-2]);

    Q.resize(0);
    for (int i=0; i<n; i++)
        Q.push_back(L[i].se);

    sort(Q.begin(), Q.end());
    mozliwe_y.push_back(Q[Q.size()-1]);
    mozliwe_y.push_back(Q[Q.size()-2]);

}



void akcja2(vector<pair<int, int> > &L)
{

    vector <int> Q;
    for (int i=0; i<n; i++)
        Q.push_back(L[i].fi);

    sort(Q.begin(), Q.end());
    mozliwe_X.push_back(Q[0]);
    mozliwe_X.push_back(Q[1]);

    Q.resize(0);
    for (int i=0; i<n; i++)
        Q.push_back(L[i].se);

    sort(Q.begin(), Q.end());
    mozliwe_y.push_back(Q[0]);
    mozliwe_y.push_back(Q[1]);

}


main()
{
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout.setf(ios::fixed);

    cin>>n;
    L.resize(n);
    P=L;

    for (int i=0; i<n; i++)
        cin>>L[i].fi>>L[i].se>>P[i].fi>>P[i].se;
    akcja1(L);
    akcja2(P);

    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
        {
            if(sprawdzenie(mp(mozliwe_X[i],mozliwe_y[j])))
            {
                cout <<mozliwe_X[i]<<" "<<mozliwe_y[j]<<endl;
                return 0;
            }

        }
}
#include<bits/stdc++.h>
using namespace std;

#define pii pair <int, int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back

struct punkt
{
    pii poz;
    pii docel;
    int numer;
    void wypisz()
    {
    cout <<numer<<": ( "<<poz.st<<" "<<poz.nd<<" ),  ( "<<docel.st<<" "<<docel.nd<<" )"<<endl;
    }
};

vector <int > czy_odwiedzony;
vector <int> poprzednik;
vector <punkt> P;
vector <vector <punkt> > pref;
queue<pair<int, pii> > Q;
int n;
const int stala=200;

bool porownaniey (punkt &A, punkt &B)
{
    return A.poz.nd>B.poz.nd;
}

bool porownaniex (punkt &A, punkt &B)
{
    return A.poz.st<B.poz.st;
}

void wczytywanie()
{
    cin>>n;
    czy_odwiedzony.resize(n+5, 0);
    poprzednik.resize(n+5,-1);
    pref.resize(n/stala+5);

    for (int i=0; i<n; i++)
    {
        punkt A;
        A.numer=i;
        int a,b;
        cin>>a>>b;
        A.poz=mp(a,b);
        cin>>a>>b;
        A.docel=mp(a,b);
        P.push_back(A);
    }
   // for (int i=0;i<n;i++)
     //   P[i].wypisz();
}

void rob (pii X, int x)
{
    for (int i=0; i<pref.size(); i++)
    {
        bool czy_to_ten=false;

        for (int j=pref[i].size()-1; j>=0; j--)
        {
            if( pref[i][j].poz.nd<=X.nd)
            {
                if(pref[i][j].poz.st>X.st)
                {
                    czy_to_ten=true;
                    break;
                }
                else
                {
                    if(czy_odwiedzony[pref[i][j].numer]==0)
                    {
                        poprzednik[pref[i][j].numer]=x;
                        czy_odwiedzony[pref[i][j].numer]=czy_odwiedzony[x]+1;
                        Q.push(mp(pref[i][j].numer,pref[i][j].docel ));
                    }
                    pref[i].pop_back();
                }
            }
            else
            {
                break;
            }

        }
        if(czy_to_ten)
        {
            auto A=pref[i];
            pref[i].clear();
            for (auto S :A)
            {
                if(S.poz.nd<=X.nd && S.poz.st<=X.st)
                {
                    if(czy_odwiedzony[S.numer]==0)
                    {
                        poprzednik[S.numer]=x;
                        czy_odwiedzony[S.numer]=czy_odwiedzony[x]+1;
                        Q.push(mp(S.numer,S.docel));
                    }
                }
                else
                    pref[i].push_back(S);
            }
            break;
        }
    }
}

void akcja()
{
    sort(P.begin(), P.end(), porownaniex);
    for (int i=0; i<P.size(); i++)
    {
        pref[i/stala].pb(P[i]);
    }
    for (int i=0; i<pref.size(); i++)
        sort(pref[i].begin(), pref[i].end(), porownaniey);
/*
          for (int i=0;i<n;i++)
            P[i].wypisz();
            for (int i=0;i<pref.size();i++)
            {
            cout <<i<<endl;
                for (auto S:pref[i])
                S.wypisz();
            }
*/
//return;
    Q.push(mp(n+2, mp(0,0)));
    while (!Q.empty())
    {
        auto Z=Q.front();
       // cout <<Z.st<<endl;
        Q.pop();
        rob(Z.nd, Z.st);
    }
}

main()
{
    wczytywanie();
    akcja();

    if(czy_odwiedzony[n-1]==0)
    {
        cout <<-1<<endl;
    }
    else
    {
        int x=n-1;
        vector <int> X;
        while (poprzednik[x]!=n+2)
        {
            X.pb(x);
            x=poprzednik[x];
        }
        X.pb(x);
        reverse(X.begin(), X.end());
        cout <<X.size()<<endl;
        for (auto s : X)
            cout <<s+1<<" ";
            cout <<endl;
    }
}
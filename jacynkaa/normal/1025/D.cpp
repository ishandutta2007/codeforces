#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define mp make_pair
#define se second
#define fi first
const int stala=701;


int euklides (int a,int b) //a>b
{
    while (b!=0)
    {
        int c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int wartosci[stala];
bool L [stala][stala]; //dla srodka a, w lewo dlugsosci zero
bool P [stala][stala];
int gcd [stala][stala];
int n;

void pre()
{
    cin>>n;
    for (int i=0; i<n; i++)
        cin>>wartosci[i];

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            gcd[i][j]=euklides(wartosci[i], wartosci[j]);

}

int akcja ()
{
    for (int i=0; i<n; i++)
        L[i][0]=P[i][0]=true;

    for (int j=1; j<n; j++) //dlugsoc przedzialu
        for (int i=0; i<n; i++) //wierz
        {
            int k=i+j;
            if(k<n)
            {
                for (int q=i+1; q<=k; q++)
                    if(L[q][q-i-1]==true && P[q][k-q]==true && gcd[i][q]>1)
                        P[i][j]=true;
            }
            k=i-j;
            if(k>=0)
            {
                for (int q=i-1; q>=k; q--)
                    if(P[q][i-q-1]==true && L[q][q-k]==true && gcd[i][q]>1)
                        L[i][j]=true;
            }
        }
    for (int i=0; i<n; i++)
    {
        if(L[i][i]==true &&P[i][n-i-1]==true)
        {
            cout <<"Yes"<<endl;
            return 0;
        }
    }
    cout <<"No"<<endl;
}

main()
{
    pre();
    akcja();

}
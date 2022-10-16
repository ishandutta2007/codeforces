#include<iostream>
using namespace std;


main ()
{
int iletaxi=0;
int L [5]= {0};
int n, a;
cin >>n;
for (int i=0; i<n; i++)
{
    cin >>a;
    L[a]++;
}
iletaxi=L[4]+L[3]+L[2]/2;

L[1]=L[1]-L[3];


if( L[2]%2==1)
{  iletaxi++;
    L[1]=L[1]-2;
}

if (L[1]>0)
{iletaxi=iletaxi+L[1]/4;
if (L[1]%4==0)
{}
else
iletaxi++;

}

cout <<iletaxi;
}
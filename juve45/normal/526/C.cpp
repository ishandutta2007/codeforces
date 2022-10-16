#include <iostream>
#include <cstdio>

using namespace std;

long long a, C, W, h1,h2,w1,w2;

int main()
{
    //freopen("in.txt", "r", stdin);
    cin>>C>>h1>>h2>>w1>>w2;


        if(w1>C && w2>C)
        {
            cout<<0<<'\n';
            return 0;
        }

    long long k=C/w1;

    long long C2=k*h1;

    long long a=0;
    long long smax=C2;
    long long W=w1*k;

    while(a<7000000 && k>=0)
    {

        W=w1*k;
        long long g=(C-W)/w2;
        C2=k*h1+g*h2;
        if(C2>smax)
            smax=C2;
        a++;
        k--;
    }

long long aux=h1;
        h1=h2;
        h2=aux;
        aux=w1;
        w1=w2;
        w2=aux;

    k=C/w1;

    C2=k*h1;

    a=0;
    //smax=C2;
    W=w1*k;

    while(a<7000000 && k>=0)
    {

        W=w1*k;
        long long g=(C-W)/w2;
        C2=k*h1+g*h2;
        if(C2>smax)
            smax=C2;
        a++;
        k--;
    }

    cout<<smax<<'\n';

    return 0;
}
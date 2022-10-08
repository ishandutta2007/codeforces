//Bartosz Kostka
//You are not prepared!

#include "bits/stdc++.h"

using namespace std;

vector <vector <int> > X;

bool solve(int a, int b, int k, int d, int n)
{
    if(a>=b)
        return false;
    if(d<1)
        return false;
    int grupa = ceil(1.0*(b-a)/k);
    //printf("%d %d %d\n", d, a, b);
    int ile = 0;
    for(int i=0; ile<b-a && i<k; i++)
    {
        for(int j=0; ile<b-a && j<grupa; j++)
        {
            ile++;
            X[d-1].push_back(i);
        }
        if(grupa >= 1)
            solve(a+i*grupa,min(b,a+(i+1)*grupa),k,d-1,n);
    }
}

bool check(int n, int d)
{
    if(n==1)
        return true;
    for(int i=0; i<d; i++)
        if(X[i][0] != X[i][1])
            return true;
    return false;
}

int main()
{
    int n, k, d;
    scanf("%d%d%d", &n, &k, &d);
    X.resize(d);
    solve(0,n,k,d,n);
    for(int i=0; i<d; i++)
        if(X[i].size()<n)
            X[i].resize(n);
    if(check(n,d))
    {
        for(int i=0; i<d; i++)
        {
            for(int j=0; j<n; j++)
                printf("%d ", X[i][j]+1);
            printf("\n");
        }
    }
    else
        printf("-1");
    return 0;
}
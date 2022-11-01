#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long N;
    scanf("%I64d",&N);
    long long odp = 0;
    long long p = 9;
    long long dod = 1;
    while (N != 0)
    {
        if (N > p)
        {
            N -= p;
            odp += dod*p;
        }
        else
        {
            odp += dod*N;
            N = 0;
        }
        dod++;
        p *= 10;
    }
    printf("%I64d",odp);
}
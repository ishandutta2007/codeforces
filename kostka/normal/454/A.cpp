//Bartosz Kostka
//You are not prepared!

#include "bits/stdc++.h"

using namespace std;

void linia(int a, int b, int c)
{
    for(int i=0; i<a; i++)
        printf("*");
    for(int i=0; i<b; i++)
        printf("D");
    for(int i=0; i<c; i++)
        printf("*");
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    int a = (n-1)/2, b = 1;
    for(int i=0; i<n; i++)
    {
        linia(a,b,a);
        if(i<n/2)
        {
            a -= 1;
            b += 2;
        }
        else
        {
            a += 1;
            b -= 2;
        }
    }
    return 0;
}
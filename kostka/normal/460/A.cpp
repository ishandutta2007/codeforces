//Bartosz Kostka
//You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=1; true; i++)
    {
        n--;
        if(i%m==0)
            n++;
        if(n==0)
        {
            printf("%d\n", i);
            return 0;
        }
    }
    
    return 0;
}
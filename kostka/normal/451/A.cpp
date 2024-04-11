//Bartosz Kostka
//You are not prepared!

#include "bits/stdc++.h"

using namespace std;

void test()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int a = min(n,m);
    if(a%2)
        puts("Akshat");
    else
        puts("Malvika");
    return;
    
}

int main()
{
    int t = 1;
    while(t--)
        test();
    return 0;
}
//Bartosz Kostka
//You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int a[10], b[10];
int wyn = 10007;

void test()
{
    string t, x;
    cin >> t >> x;
    for(int i=0; t[i]; i++)
        a[t[i]-'0']++;
    for(int i=0; x[i]; i++)
        b[x[i]-'0']++;
    a[5] += a[2];
    a[2] = 0;
    a[6] += a[9];
    a[9] = 0;
    b[5] += b[2];
    b[2] = 0;
    b[6] += b[9];
    b[9] = 0;
    for(int i=0; i<=9; i++)
        if(a[i])
            wyn = min(wyn, b[i]/a[i]);
    printf("%d\n", wyn);
}

int main()
{
    int t = 1;
    while(t--)
        test();
    return 0;
}
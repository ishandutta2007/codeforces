//Bartosz Kostka
//You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 100007;
int ile[MAXN];

void test()
{
    string x;
    cin >> x;
    int n = x.size();
    ile[1] = 1;
    for(int i=1; i<n; i++)
        ile[i+1] = ile[i] + (x[i] != x[i-1]);
    long long wynp = 0, wynn = n;
    long long nn = 0, np = 0, pn = 0, pp = 0;
    for(int i=1; i<=n; i++)
    {
        if(i%2)
        {
            if((ile[i])%2)
            {
                wynn += nn;
                wynp += np;
                nn++;
            }
            else
            {
                wynn += pn;
                wynp += pp;
                pn++;
            }
        }
        else
        {
            if((ile[i])%2)
            {
                wynn += np;
                wynp += nn;
                np++;
            }
            else
            {
                wynn += pp;
                wynp += pn;
                pp++;
            }
        }
    }
    printf("%lld %lld\n", wynp, wynn);
    
}

int main()
{
    int t = 1;
    while(t--)
        test();
    return 0;
}
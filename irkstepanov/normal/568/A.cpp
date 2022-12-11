#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#define mp std::make_pair
#define pb push_back

#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()

using namespace std;

const int nmax = 10000000;

typedef long long ll;

int main()
{

    bool prime[nmax];
    prime[1] = false;
    for (int i = 2; i < nmax; i++)
        prime[i] = true;
    for (int i = 2; i < nmax; i++)
        if (prime[i])
    {
        for (int j = 2; i * j < nmax; j++)
            prime[i * j] = false;
    }

    bool pal[nmax];
    for (int i = 1; i < nmax; i++)
    {
        char buffer[33];
        itoa(i, buffer, 10);
        pal[i] = true;
        int s = 0;
        for (; buffer[s]; s++) ;
        for (int j = 0; j < s - j - 1; j++)
            if (buffer[j] != buffer[s - j - 1]) pal[i] = false;
    }

    ll q, p;
    cin >> p >> q;
    ll a = 0, b = 0;
    int ans = -1;

    for (int i = 1; i < nmax; i++)
    {
        if (prime[i]) ++a;
        if (pal[i]) ++b;
        if (a * q <= p * b) ans = i;
        //if (i == 2000000) cout << a << " " << b << " " << a * 1.0 / b << "\n";
    }

cout << ans << "\n";

}
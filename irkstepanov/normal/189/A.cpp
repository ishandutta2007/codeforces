#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>

#define pb push_back

using namespace std;

int main()
{

    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int d[5000];
    for (int i = 0; i < 5000; i++)
        d[i] = -1000000000;
    d[0] = 0;

    for (int i = 0; i < 5000; i++)
    {
        if (i + a < 5000) d[i + a] = max(d[i + a], d[i] + 1); //if (i < 50) {cout << i << " " << i + a << " " << d[i] << " " << d[i + a] << "\n";}}
        if (i + b < 5000) d[i + b] = max(d[i + b], d[i] + 1); //if (i < 50) {cout << i << " " << i + b << " " << d[i] << " " << d[i + b] << "\n";}}
        if (i + c < 5000) d[i + c] = max(d[i + c], d[i] + 1); //if (i < 50) {cout << i << " " << i + c << " " << d[i] << " " << d[i + c] << "\n";}}
    }

    cout << d[n];

}
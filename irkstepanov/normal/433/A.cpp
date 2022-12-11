#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

#define pb push_back
#define mp make_pair

using namespace std;

typedef vector <int> vi;

const int inf = 1000000000;

int main()
{

    int n, a = 0, b = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int w;
        cin >> w;
        if (w == 100) ++a;
        else ++b;
    }

    for (int c = 0; c <= a; c++)
        for (int d = 0; d <= b; d++)
        if (2 * c + 4 * d == a + 2 * b) {cout << "YES"; return 0;}

    cout << "NO";

}
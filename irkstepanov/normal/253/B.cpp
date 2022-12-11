#include <iostream>
#include <fstream>
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

    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int n;
    cin >> n;
    int c[6000];

    for (int i = 1; i <= 5000; i++)
        c[i] = 0;

    for (int i = 0; i < n; i++)
    {
        int r;
        cin >> r;
        ++c[r];
    }

    int sum[6000];
    sum[0] = 0;
    for (int i = 1; i <= 5000; i++)
        sum[i] = sum[i - 1] + c[i];

    int ans = inf;

    for (int l = 1; l <= 5000; l++)
        for (int r = l; r <= 5000; r++)
        if (r <= 2 * l)
    {
        int x = n - (sum[r] - sum[l - 1]);
        if (ans > x) ans = x;
    }

    cout << ans;

}
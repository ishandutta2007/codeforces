#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>

#define pb push_back
#define mp make_pair

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef long double ld;

int main()
{

    int n;
    cin >> n;

    int a[100500];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int b;
    for (b = 1; b < n; b++)
        if (a[b] < a[b - 1]) break;

    if (b == n) {cout << "0\n"; return 0;}

    for (int i = b + 1; i < n; i++)
        if (a[i] < a[i - 1]) {cout << "-1\n"; return 0;}

    if (a[n - 1] > a[0]) {cout << "-1\n"; return 0;}
    cout << n - b << "\n";

    return 0;

}
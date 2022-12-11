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

    int l = (n - 1) / 2, r = (n - 1) / 2;

    while (l)
    {
        for (int i = 0; i < n; i++)
            if (i >= l && i <= r) cout << 'D';
            else cout << '*';
        --l, ++r;
        cout << "\n";
    }

    for (int i = 0; i < n; i++)
        cout << 'D';
    cout << "\n";

    l = 1, r = n - 2;
    while (l <= r)
    {
        for (int i = 0; i < n; i++)
            if (i >= l && i <= r) cout << 'D';
            else cout << '*';
        ++l, --r;
        cout << "\n";
    }

    return 0;

}
#include <bits/stdc++.h>

#define x first
#define y second

#define mp make_pair
#define pb push_back

using namespace std;

typedef pair <int, int> cell;

int main()
{

    long long n, k;
    cin >> n >> k;

    long long nech = (n + 1) / 2;
    if (k <= nech)
    {
        cout << 2 * k - 1;
    }
    else
    {
        k -= nech;
        cout << 2 * k;
    }

}
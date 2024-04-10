#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

ll n, m, k;
int arr[100];

ll fact(ll n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}

int main()
{
    cin >> n >> m;
    k = min(n, m);
    cout << fact(k);
}
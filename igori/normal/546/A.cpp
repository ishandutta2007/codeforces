#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int k, n, w;
    cin >> k >> n >> w;
    int c = w * (w + 1) / 2 * k;
    if (c < n) cout << 0 << "\n";
    else cout << c - n << "\n";
}
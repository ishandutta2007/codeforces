#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;
    vector <int> f(m);

    for (int i = 0; i < m; i++)
        cin >> f[i];

    sort(f.begin(), f.end());

    int otv = f[n - 1] - f[0];
    for (int i = n; i < m; i++)
        otv = min(otv, f[i] - f[i - n + 1]);

    cout << otv;

}
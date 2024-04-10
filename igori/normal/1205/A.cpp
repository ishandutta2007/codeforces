#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define int long long

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

long long n;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    if (n % 2 == 0)
    {
        cout << "NO";
        return 0;
    }
    vector<int> kek(2 * n);
    for (int i = 0; i < n; i++)
    {
        kek[i] = 2 * i;
        kek[i + n] = 2 * i;
        if (i % 2) kek[i]++;
        else kek[i + n]++;
    }
    cout << "YES\n";
    for (int i = 0; i < 2 * n; i++) cout << kek[i] + 1 << " ";
}
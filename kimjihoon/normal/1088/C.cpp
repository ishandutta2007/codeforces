#include <iostream>
using namespace std;

int a[2009];

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int s = 0;
    cout << n + 1 << '\n';
    for (int i = n - 1; i >= 0; i--) {
        int t = (i + n - ((s + a[i]) % n)) % n;
        cout << 1 << " " << i + 1 << " " << t << '\n';
        s += t;
    }
    cout << 2 << " " << n << " " << n << '\n';
    return 0;
}
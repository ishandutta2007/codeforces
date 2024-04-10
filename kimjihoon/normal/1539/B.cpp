#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int ss[100009];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q; cin >> n >> q;
    string s; cin >> s;
    for (int i = 1; i <= n; i++) 
        ss[i] = ss[i - 1] + (int)(s[i - 1] - 'a') + 1;
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        cout << ss[r] - ss[l - 1] << '\n';
    }
    return 0;
}
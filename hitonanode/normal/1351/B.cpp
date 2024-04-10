#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;

int main()
{
    int TC;
    cin >> TC;
    while (TC--)
    {
        int a1, b1, a2, b2;
        cin >> a1 >> b1 >> a2 >> b2;
        if (a1 > b1) swap(a1, b1);
        if (a2 > b2) swap(a2, b2);
        cout << (b1 == b2 and a1 + a2 == b1 ? "Yes\n" : "No\n");
    }
}
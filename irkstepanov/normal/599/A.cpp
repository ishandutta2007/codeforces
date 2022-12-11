#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 2 * a + 2 * b;
    ans = min(ans, a + c + b);
    ans = min(ans, a + c + c + a);
    ans = min(ans, b + c + c + b);
    cout << ans << "\n";
}
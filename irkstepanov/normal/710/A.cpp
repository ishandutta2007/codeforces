#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    char a, b;
    cin >> a >> b;

    int ans = 0;
    for (char x = 'a'; x <= 'h'; ++x) {
        for (char y = '1'; y <= '8'; ++y) {
            if (abs(a - x) <= 1 && abs(b - y) <= 1) {
                ++ans;
            }
        }
    }
    cout << ans - 1 << "\n";

}
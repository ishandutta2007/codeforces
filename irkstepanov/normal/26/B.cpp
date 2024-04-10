#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{

    //freopen("input.txt", "r", stdin);

    string s;
    cin >> s;
    int close = 0;
    for (int i = 0; i < sz(s); ++i) {
        if (s[i] == ')') {
            ++close;
        }
    }

    int balance = 0, ans = 0;
    for (int i = 0; i < sz(s); ++i) {
        if (s[i] == '(') {
            if (close >= balance + 1) {
                ++balance;
                ++ans;
            }
        } else {
            --close;
            if (balance) {
                --balance;
                ++ans;
            }
        }
    }
    cout << ans << "\n";

}
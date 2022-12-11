#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(a) static_cast<int>((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

typedef long long ll;

ll f(const string& s)
{
    ll ans = 0;
    for (int i = 0; i < sz(s); ++i) {
        ans *= 2;
        ans += (s[i] - '0');
    }
    return ans;
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    ll a, b;
    int ans = 0;
    cin >> a >> b;

    for (int len = 2; len <= 62; ++len) {
        string init = "";
        for (int i = 0; i < len; ++i) {
            init += "1";
        }
        for (int i = 1; i < len; ++i) {
            string t = init;
            t[i] = '0';
            ll d = f(t);
            if (d >= a && d <= b) {
                ++ans;
            }
        }
    }

    cout << ans << "\n";

}
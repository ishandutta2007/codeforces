#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;

int dist(const string& a, const string& b)
{
    int ans = 0;
    for (int i = 0; i < sz(a); ++i) {
        if (a[i] != b[i]) {
            ++ans;
        }
    }
    return ans;
}

int ans = 100500;
string t;

void solve(const string& s, int h, int m)
{
    string b = "--:--";
    b[1] = (char)(h % 10 + '0');
    b[0] = (char)(h / 10 + '0');
    b[4] = (char)(m % 10 + '0');
    b[3] = (char)(m / 10 + '0');
    if (dist(s, b) < ans) {
        ans = dist(s, b);
        t = b;
    }
}

int main()
{

    //ifstream cin("input.txt");

    int k;
    cin >> k;

    string s;
    cin >> s;

    if (k == 12) {
        int h = 1, m = 0;
        while (true) {
            solve(s, h, m);
            ++m;
            if (m == 60) {
                m = 0;
                ++h;
            }
            if (h > 12) {
                break;
            }
        }
    } else {
        int h = 0, m = 0;
        while (true) {
            solve(s, h, m);
            ++m;
            if (m == 60) {
                m = 0;
                ++h;
            }
            if (h > 23) {
                break;
            }
        }
    }

    cout << t << '\n';

}
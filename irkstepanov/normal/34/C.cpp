#include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, int> pll;

const int inf = 1e9;

string s;

int get(int pos)
{
    int ans = 0;
    while (pos < sz(s) && s[pos] != ',') {
        ans *= 10;
        ans += (s[pos] - '0');
        ++pos;
    }
    return ans;
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    vector<char> cnt(1010, false);
    cin >> s;
    int pos = 0;
    while (pos < sz(s)) {
        int g = get(pos);
        cnt[g] = true;
        while (pos < sz(s) && s[pos] != ',') {
            ++pos;
        }
        ++pos;
    }

    int prev = -1;
    bool out = false;
    for (int i = 1; i < 1010; ++i) {
        if (cnt[i]) {
            if (prev == -1) {
                prev = i;
                if (out) {
                    cout << ",";
                }
                cout << i;
                out = true;
            }
        } else {
            if (prev == i - 1) {
                prev = -1;
            } else if (prev != -1) {
                cout << "-" << i - 1;
                prev = -1;
            }
        }
    }
    cout << "\n";

}
#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    string s;
    cin >> s;

    int c[10];
    memset(c, 0, 10 * sizeof(int));
    for (int i = 0; i < sz(s); ++i) {
        ++c[s[i] - '0'];
    }

    string ans = "";
    if (s == "0") {
        ans = s;
    } else {
        for (int i = 1; i < 10; ++i) {
            if (c[i]) {
                ans += (char)(i + '0');
                --c[i];
                break;
            }
        }
        for (int i = 0; i < 10; ++i) {
            while (c[i]) {
                ans += (char)(i + '0');
                --c[i];
            }
        }
    }

    string t;
    cin >> t;

    cout << (ans == t ? "OK\n" : "WRONG_ANSWER\n");

}
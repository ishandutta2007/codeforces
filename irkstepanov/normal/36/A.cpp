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

int main()
{

    ifstream cin("input.txt");
    ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int a = -1, b;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            if (a == -1) {
                a = i;
            } else {
                b = i;
                break;
            }
        }
    }

    int prev = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            if (prev == -1) {
                prev = i;
            } else {
                if (i - prev != b - a) {
                    cout << "NO\n";
                    return 0;
                }
                prev = i;
            }
        }
    }
    cout << "YES\n";

}
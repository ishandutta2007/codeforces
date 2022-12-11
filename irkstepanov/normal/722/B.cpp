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

bool vowel(char c)
{
    return c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u' || c == 'y';
}

int main()
{

    //ifstream cin("input.txt");

    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    string s;
    getline(cin, s);

    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        int cnt = 0;
        for (int j = 0; j < sz(s); ++j) {
            if (vowel(s[j])) {
                ++cnt;
            }
        }
        if (cnt != p[i]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

}
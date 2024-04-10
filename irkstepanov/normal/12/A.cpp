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

    char c[3][3];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> c[i][j];
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (c[i][j] != c[2 - i][2 - j]) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";

}
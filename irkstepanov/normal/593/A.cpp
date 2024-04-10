#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()

using namespace std;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n;
    cin >> n;

    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int ans = 0;
    for (char a = 'a'; a <= 'z'; ++a) {
        for (char b = 'a'; b <= 'z'; ++b) {
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                bool ok = true;
                for (int j = 0; j < sz(v[i]); ++j) {
                    if (v[i][j] != a && v[i][j] != b) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    cnt += sz(v[i]);
                }
            }
            ans = max(ans, cnt);
        }
    }

    cout << ans << "\n";

}
#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ofstream cout("output.txt");

    int tt;
    cin >> tt;

    while (tt--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        string t = s;
        reverse(all(t));
        if (s == t || k == 0) {
            cout << "1\n";
            continue;
        }
        cout << "2\n";
    }

}
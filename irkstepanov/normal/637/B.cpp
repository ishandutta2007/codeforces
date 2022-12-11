#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<string> input(n);
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }

    set<string> s;
    for (int i = n - 1; i >= 0; --i) {
        if (s.count(input[i])) {
            continue;
        }
        cout << input[i] << "\n";
        s.insert(input[i])
;    }

}
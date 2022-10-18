#include <bits/stdc++.h>
using namespace std;

void f() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    vector<int> minimum(n, 0);
    {
        int next = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == '>')
                minimum[i+1] = next++;
        }
        minimum[0] = next++;

        for (int i = n - 2; i >= 0; i--) {
            if (minimum[i] > 0) {
                for (int j = i + 1; j < n && minimum[j] == 0; j++) {
                    minimum[j] = next++;
                }
            }
        }
    }

    vector<int> largest(n, 0);
    {
        int last = -1;
        int next = 1;
        for (int i = 0; i < n-1; i++) {
            if (s[i] == '<') {
                for (int j = i; j > last; j--) {
                    largest[j] = next++;
                }
                last = i;
            }
        }
        for (int j = n-1; j > last; j--) {
            largest[j] = next++;
        }
    }

    for (auto x : minimum) {
        cout << x << ' ';
    }
    cout << '\n';
    for (auto x : largest) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        f();
    }
}
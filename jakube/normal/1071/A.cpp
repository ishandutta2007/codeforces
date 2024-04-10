#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;
    
    int L = 0; // possible
    int R = 100'000; // not
    while (L + 1 < R) {
        int M = (L + R) / 2;
        vector<int> p, q;
        int A = a;
        int B = b;
        bool possible = true;
        for (int i = M; i >= 1; i--) {
            if (i > A && i > B) {
                possible = false;
                break;
            }
            if (A > B) {
                A -= i;
                p.push_back(i);
            } else {
                q.push_back(i);
                B -= i;
            }
        }
        if (possible)
            L = M;
        else
            R = M;
    }

    vector<int> p, q;
    int A = a;
    int B = b;
    for (int i = L; i >= 1; i--) {
        if (A > B) {
            A -= i;
            p.push_back(i);
        } else {
            q.push_back(i);
            B -= i;
        }
    }
    cout << (int)p.size() << '\n';
    for (auto x : p) {
        cout << x << ' ';
    }
    cout << '\n';
    cout << (int)q.size() << '\n';
    for (auto x : q) {
        cout << x << ' ';
    }
    cout << '\n';
}
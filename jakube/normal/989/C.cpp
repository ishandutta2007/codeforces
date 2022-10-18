#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<vector<char>> M(50, vector<char>(50));
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 50; j++) {
            M[i][j] = 'A';
        }
    }
    a--;
    for (int i = 25; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            M[i][j] = 'B';
        }
    }
    b--;

    for (int i = 1; i < 25; i+=2) {
        for (int j = 1; j < 50; j+=2) {
            if (b) {
                M[i][j] = 'B';
                b--;
            } else if (c) {
                M[i][j] = 'C';
                c--;
            }
        }
    }
    for (int i = 26; i < 50; i+=2) {
        for (int j = 1; j < 50; j+=2) {
            if (a) {
                M[i][j] = 'A';
                a--;
            } else if (d) {
                M[i][j] = 'D';
                d--;
            }
        }
    }

    cout << "50 50" << '\n';
    for (auto& row : M) {
        for (char c : row)
            cout << c;
        cout << endl;
    }
}
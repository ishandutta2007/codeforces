#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> v(10);
    for (int i = 0; i < 10; i++) {
        cin >> v[i];
    }
    
    bool possible = false;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j + 4 < 10; j++) {
            int x = 0;
            int dot = 0;
            for (int k = 0; k < 5; k++) {
                if (v[i][j+k] == 'X')
                    x++;
                if (v[i][j+k] == '.')
                    dot++;
            }
            if (x==4 && dot == 1)
                possible = true;
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j + 4 < 10; j++) {
            int x = 0;
            int dot = 0;
            for (int k = 0; k < 5; k++) {
                if (v[j+k][i] == 'X')
                    x++;
                if (v[j+k][i] == '.')
                    dot++;
            }
            if (x==4 && dot == 1)
                possible = true;
        }
    }

    for (int i = 0; i + 4 < 10; i++) {
        for (int j = 0; j + 4 < 10; j++) {
            int x = 0;
            int dot = 0;
            for (int k = 0; k < 5; k++) {
                if (v[i+k][j+k] == 'X')
                    x++;
                if (v[i+k][j+k] == '.')
                    dot++;
            }
            if (x==4 && dot == 1)
                possible = true;
        }
    }

    for (int i = 0; i + 4 < 10; i++) {
        for (int j = 4; j < 10; j++) {
            int x = 0;
            int dot = 0;
            for (int k = 0; k < 5; k++) {
                if (v[i+k][j-k] == 'X')
                    x++;
                if (v[i+k][j-k] == '.')
                    dot++;
            }
            if (x==4 && dot == 1)
                possible = true;
        }
    }

    if (possible)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
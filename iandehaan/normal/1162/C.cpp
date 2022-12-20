#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    bool stuff[n][3];
    for (int i = 0; i < n; i++) {
         stuff[i][2] = true;
         stuff[i][1] = true;
         stuff[i][0] = true;
        if (i == 0) {
            stuff[i][0] = false;
        }
        if (i == n-1) {
            stuff[i][1] = false;
        }
    }

    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        x--;
        stuff[x][2] = false;
        if (x != 0) {
            if (!stuff[x-1][2]) {
                stuff[x-1][1] = false;
            }
        }
        if (x != n-1) {
            if (!stuff[x+1][2]) {
                stuff[x+1][0] = false;
            }
        }
    }
    uint64_t out = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            if (stuff[i][j]) {
                //cout << i << " " << j << endl;
                out++;
            }
        }
    }

    cout << out << endl;
}
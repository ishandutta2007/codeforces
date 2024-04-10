#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    char in[n];
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }

    int maxDepth = 0;
    int depth = 0;
    for (int i = 0; i < n; i++) {
        if (in[i] == '(') {
            depth++;
            maxDepth = max(depth, maxDepth);
        } else {
            depth--;
        }
    }

    int dd = maxDepth/2;
    // cout << dd << endl;
    depth = 0;
    for (int i = 0; i < n; i++) {
        bool flag = false;
        if (in[i] == '(') {
            depth++;
        } else {
            flag = true;
        }
        if (depth <= dd) {
            cout << 0;
        } else {
            cout << 1;
        }
        if (flag) {
            depth--;
        }
    }
    cout << endl;
}
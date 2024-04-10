#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int a[2000001];
int n;

bool strt(int sze) {
    bool visited[n+1];
    for (int i = 1; i <= n; i++) visited[i] = false;
    for (int i = 0; i < sze; i++) {
        if (visited[a[i]]) return false;
        visited[a[i]] = true;
    }

    for (int i = 1; i <= sze; i++) if (!visited[i]) return false;
    return true;
}

bool end(int sze) {
    bool visited[n+1];
    for (int i = 1; i <= n; i++) visited[i] = false;
    for (int i = n-1; i >= n-sze; i--) {
        if (visited[a[i]]) return false;
        visited[a[i]] = true;
    }

    for (int i = 1; i <= sze; i++) if (!visited[i]) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
       
        for (int i = 0; i < n; i++) cin >> a[i];

        bool visited[n+1];
        for (int i = 0; i <= n; i++) visited[i] = false;
        int biggest = -1;
        int biggestdup = -1;
        for (int i = 0; i < n; i++) {
            biggest = max(biggest, a[i]);
            if (visited[a[i]]) {
                biggestdup = max(biggestdup, a[i]);
            }
            visited[a[i]] = true;
        }

        if (biggest + biggestdup != n) {
            cout << 0 << endl;
            continue;
        }

        // check if biggest, biggestdup works
        bool bigfirst = strt(biggest) && end(biggestdup);
        bool bigsecond = strt(biggestdup) && end(biggest);
        if (bigfirst && bigsecond) {
            if (biggest == biggestdup) {
                cout << 1 << endl;
                cout << biggest << ' ' << biggestdup << endl;
                continue;
            }
            cout << 2 << endl;
            cout << biggest << ' ' << biggestdup << endl;
            cout << biggestdup << ' ' << biggest << endl;
        } else if (bigfirst) {
            cout << 1 << endl;
            cout << biggest << ' ' << biggestdup << endl;
        } else if (bigsecond) {
            cout << 1 << endl;
            cout << biggestdup << ' ' << biggest << endl;
        } else {
            cout << 0 << endl;
        }
    }
}
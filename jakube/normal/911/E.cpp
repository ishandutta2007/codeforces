#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> v(k);
    for (int i = 0; i < k; i++) {
        cin >> v[i];
        v[i]--;
    }

    vector<bool> visited(n, 0);
    for (int i = 0; i < k; i++) {
        visited[v[i]] = true;
    }
    
    int start = 0;
    while (true) {
        // find next non-visited
        while (start < n && visited[start]) {
            start++;
        }
        if (start == n)
            break;

        int to = start;
        while (to < n && visited[to] == false) {
            to++;
        }

        for (int i = to - 1; i >= start; i--) {
            v.push_back(i);
            visited[i] = true;
        }
    }

    int next = 0;
    stack<int> s;
    for (int i : v) {
        s.push(i);
        while (s.size() > 0 && s.top() == next) {
            next++;
            s.pop();
        }
    }
    if (next == n) {
        for (auto x : v) {
            cout << x + 1 << ' ';
        }
        cout << '\n';
    } else {
        cout << -1 << '\n';
    }
}
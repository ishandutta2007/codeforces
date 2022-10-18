#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long t;
    cin >> n >> t;
    vector<long long> a(n);
    for (auto& x : a)
        cin >> x;
    vector<int> x(n);
    for (auto& x : x) {
        cin >> x;
        x--;
    }
    
    vector<int> assign(n, 0);
    for (int i = 0; i < n; i++) {
        if (x[i] > i) {
            assign[i]++;
            assign[x[i]]--;
        }
    }

    vector<long long> b(n);
    int psum = 0;
    for (int i = 0; i < n; i++) {
        psum += assign[i];
        if (psum)
            b[i] = a[i+1] + t;
        else
            b[i] = a[i] + t;
    }

    // back
    for (int i = 0; i < n; i++) {
        b[x[i]] = max(b[x[i]], a[i] + t);
    }

    // +1
    for (int i = 1; i < n; i++) {
        b[i] = max(b[i-1] + 1, b[i]);
    }

    for (int i = 0; i < n; i++) {
        if (x[i] < n - 1) {
            if (b[x[i]] >= a[x[i]+1] + t) {
                cout << "No" << '\n';
                return 0;
            } 
        }
    }
    cout << "Yes" << '\n';
    for (auto x : b) {
        cout << x << ' ';
    }
    cout << '\n';
}
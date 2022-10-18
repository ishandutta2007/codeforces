#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> pxor(n), bxor(n);
    for (int i = 0; i < n; i++) {
        cout << "? " << i << " 0" << endl;
        cin >> pxor[i];
        cout << "? 0 " << i << endl;
        cin >> bxor[i];
    }

    int cnt = 0;
    vector<int> result;

    vector<int> p(n);
    vector<int> b(n);
    for (int guess = 0; guess < n; guess++) {
        bool bo = true;
        for (int i = 0; i < n; i++) {
            p[i] = pxor[i] ^ guess;
            if (p[i] >= n)
                bo = false;
        }
        if (!bo)
            continue;

        for (int i = 0; i < n; i++) {
            b[p[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            if ((p[i] ^ b[0]) != pxor[i])
                bo = false;
            if ((p[0] ^ b[i]) != bxor[i])
                bo = false;
        }

        if (bo) {
            cnt++;
            result = p;
        }
    }

    cout << "!" << endl;
    cout << cnt << endl;
    for (int i = 0; i < n; i++)
        cout << result[i] << " ";
    cout << endl;
}
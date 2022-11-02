#include <bits/stdc++.h>

using namespace std;

int read() {
    int x;
    cin >> x;
    string s;
    for (int i = 0; i < x; ++i) {
        cin >> s;
    }
    return x;
}

int main() {
    do {
        cout << "next 0 1" << endl;
        read();
        cout << "next 0" << endl;
    } while (read() > 2);
    do {
        cout << "next 0 1 2 3 4 5 6 7 8 9" << endl;
    } while (read() > 1);
    cout << "done" << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string n, m;
    cin >> n >> m;
    auto time = [](string x) {
        return ((x[0] - '0') * 10 + (x[1] - '0')) * 60 + ((x[3] - '0') * 10 + (x[4] - '0'));
    };
    int x = time(n);
    int y = time(m);
    int z = (x + y) / 2;

    int h = z / 60;
    int min = z % 60;
    if (h < 10)
        cout << "0";
    cout << h << ":";
    if (min < 10)
        cout << "0";
    cout << min << endl;
}
#include <bits/stdc++.h>
using namespace std;

void print(char c, int cnt) {
    for (int i = 0; i < cnt; i++) {
        cout << c;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, k, a, b;
    cin >> n >> k >> a >> b;

    char letters[] = {'G', 'B'};
    if (b > a) {
        swap(a, b);
        swap(letters[0], letters[1]);
    }

    int nr = a / k + (a % k > 0);
    if (b < nr - 1) {
        cout << "NO" << endl;
        return 0;
    }

    while (a) {
        print(letters[0], min(k, a));
        a -= min(k, a);

        int tmp = min(b, max(0, min(k, b - (a / k + (a % k > 0) - 1))));
        print(letters[1], tmp);
        b -= tmp;
    }
    cout << endl;


    return 0;
}
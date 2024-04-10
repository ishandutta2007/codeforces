#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    a--, b--;
    int round = 0;
    while (a != b) {
        round++;
        a /= 2, b /= 2;
        n /= 2;
    }
    if (n == 1)
        cout << "Final!" << endl;
    else 
        cout << round << endl;
}
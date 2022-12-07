#include <bits/stdc++.h>
using namespace std;

string a, b;
int n;
int main() {
    cin >> a >> b;
    scanf("%d", &n);
    cout << a << " " << b << endl;
    string c, d;
    while (n--) {
        cin >> c >> d;
        if (a == c) a = d;
        else if (b == c) b = d;
        cout << a << " " << b << endl;
    }
    return 0;
}
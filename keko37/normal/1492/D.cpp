#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int zero, one, k;

void ispis (int c, int len) {
    for (int i = 0; i < len; i++) cout << c;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> zero >> one >> k;
    if (one == 1 || zero == 0) {
        if (k != 0) {
            cout << "No";
        } else {
            cout << "Yes\n";
            ispis(1, one); ispis(0, zero); cout << endl;
            ispis(1, one); ispis(0, zero); cout << endl;
        }
    } else {
        if (one + zero - (k + 1) <= 0) {
            cout << "No";
        } else if (k > zero) {
            cout << "Yes\n";
            ispis(1, one); ispis(0, zero); cout << endl;
            ispis(1, one + zero - (k + 1)); ispis(0, 1); ispis(1, k - zero); ispis(0, zero - 1); ispis(1, 1); cout << endl;
        } else {
            cout << "Yes\n";
            ispis(1, one - 1); ispis(0, zero - k); ispis(1, 1); ispis(0, k); cout << endl;
            ispis(1, one - 1); ispis(0, zero); ispis(1, 1); cout << endl;
        }
    }
    return 0;
}
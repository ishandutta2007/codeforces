#include <iostream>
using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    bool num[n];
    for (int i = 0; i < n; i++) {
        char x;
        cin >> x;
        if (x == '1') {
            num[n-i-1] = true;
        } else {
            num[n-i-1] = false;
        }
    }
    int cnt = 0;
    for (int i = 0; i < x; i++) {
        if (i == y && !num[i]) {
            cnt++;
        } else if (i != y) {
            if (num[i]) {
                cnt++;
            }
        }
    } 
    cout << cnt << endl;
}
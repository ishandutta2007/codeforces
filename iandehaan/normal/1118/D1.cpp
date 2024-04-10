#include <iostream>
#include <algorithm>
using namespace std;

int cups[100];
int n, m;

bool possible(int x) {
    //cout << x << endl;
    int daily = n/x;
    int firstn = n%x;
    int ind = 0;
    int left = m;
    for (int i = 0; i < firstn; i++) {
        left -= max(0, cups[ind]-daily);
        ind++;
    }
    for (int i = 0; i < daily; i++) {
        int off = daily-i-1;
        for (int j = 0; j < x; j++) {
            left -= max(0, cups[ind]-off);
            ind++;
        }
        //cout << i << ' ' << m << endl;
    }
    //cout << left << endl;
    return left <= 0;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> cups[i];
    sort(cups, cups+n);
    int test = 1;
    while (!possible(test)) {
        test++;

        if (test > n+1) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << test << endl;
}
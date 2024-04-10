#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int num[6] = {4, 8, 15, 16, 23, 42};
int q[6];

int sq(int n) {
    int i=0;
    while (i*i<n) ++i;

    return i*i;
}
int main() {
    fflush(stdout);
    cout << "? 1 2\n";
    cin >> q[0];

    fflush(stdout);
    cout << "? 1 3\n";
    cin >> q[1];

    fflush(stdout);
    cout << "? 4 5\n";
    cin >> q[2];

    fflush(stdout);
    cout << "? 4 6\n";
    cin >> q[3];

    do {
        if (num[0]*num[1] == q[0] &&
            num[0]*num[2] == q[1] &&
            num[3]*num[4] == q[2] &&
            num[3]*num[5] == q[3] )
                break;
    }
    while (next_permutation(num, num+6));

    fflush(stdout);
    cout << "! ";
    for (int i=0; i<6; i++) {
        fflush(stdout);
        cout << num[i] << " ";
    }
}
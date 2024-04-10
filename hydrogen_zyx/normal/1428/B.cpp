#include <iostream>
using namespace std;
char a[1000000];
int main() {
    int t;
    cin >> t;
    int cnt1, cnt2, cnt3;
    while (t--) {
        int m;
        cin >> m;
        cnt1 = cnt2 = cnt3 = 0;
        for (int i = 0; i < m; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            if (a[i] == '-') cnt1++;
            if (a[i] == '-' && a[(i + m - 1) % m] != '-') cnt1++;
            if (a[i] == '<' || a[i] == '-') cnt2++;
            if (a[i] == '>' || a[i] == '-') cnt3++;
        }
        if (cnt3 == m || cnt2 == m )
            cout << m << endl;
        else if (cnt1)
            cout << cnt1 << endl;
        else
            cout << 0 << endl;
    }
}
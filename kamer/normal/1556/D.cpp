#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <string>
#include <utility>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;

int and_query(int i, int j) {
    cout << "and " << i << " " << j << "\n";
    cout.flush();
    int res;
    cin >> res;
    return res;
}

int or_query(int i, int j) {
    cout << "or " << i << " " << j << "\n";
    cout.flush();
    int res;
    cin >> res;
    return res;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int n, k;
    cin >> n >> k;
    vector<int> a(n, 0);
    
    int and01 = and_query(1, 2), and02 = and_query(1, 3), and12 = and_query(2, 3);
    int or01 = or_query(1, 2), or02 = or_query(1, 3), or12 = or_query(2, 3);

    vector<int> masks(31, 1);
    for (int i = 1; i < 31; i++) {
        masks[i] = (1 << i);
    }

    for (int i = 0; i < 31; i++) {
        int mask = masks[i];
        int mor01 = or01 & mask, mor02 = or02 & mask, mor12 = or12 & mask;
        int mand01 = and01 & mask, mand02 = and02 & mask, mand12 = and12 & mask;
        int notCount = 0;
        if (!mor01 && !mor02 && !mor12) continue;
        if (mor01 && mor02 && mor12) {
            if (mand01 && mand02 && mand12) {
                a[0] |= mask, a[1] |= mask, a[2] |= mask;
            } else {
                if (mand01) a[0] |= mask, a[1] |= mask;
                if (mand02) a[0] |= mask, a[2] |= mask;
                if (mand12) a[1] |= mask, a[2] |= mask;
            }
        } else {
            if (mor01 && mor02) a[0] |= mask;
            if (mor01 && mor12) a[1] |= mask;
            if (mor02 && mor12) a[2] |= mask;
        }
    }
    for (int i = 4; i <= n; i++) {
        a[i - 1] = a[0] ^ and_query(1, i) ^ or_query(1, i);
    }

    sort(a.begin(), a.end());
    cout << "finish " << a[k - 1] << "\n";
    cout.flush();
}
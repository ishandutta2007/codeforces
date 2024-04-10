#include <iostream>
#include <algorithm>
using namespace std;

int64_t cups[200000];
int64_t n, m;

bool possible(int64_t x) {
    if (x == 0) return false;
    //cout << x << endl;
    int64_t daily = n/x;
    int64_t firstn = n%x;
    int64_t ind = 0;
    int64_t left = m;
    int64_t zero = 0;
    for (int64_t i = 0; i < firstn; i++) {
        left -= max(zero, cups[ind]-daily);
        ind++;
    }
    for (int64_t i = 0; i < daily; i++) {
        int64_t off = daily-i-1;
        for (int64_t j = 0; j < x; j++) {
            left -= max(zero, cups[ind]-off);
            ind++;
        }
        //cout << i << ' ' << m << endl;
    }
    //cout << left << endl;
    return left <= 0;
}

int main() {
    cin >> n >> m;
    for (int64_t i = 0; i < n; i++) cin >> cups[i];
    sort(cups, cups+n);
    int64_t test = 1;
    int64_t upper = n+1;
    int64_t lower = 1;
    if (!possible(upper)) {
        cout << -1 << endl;
        return 0;
    }

    while (true) {
        if (upper <= lower && possible(lower)) {
            break;
        }

        int64_t mid = (lower + upper)/2;
        //cout << lower << ' ' << upper << ' ' << mid << endl;
        if (possible(mid)) {
            upper = mid-1;
        } else {
            lower = mid+1;
        }
    }

    cout << lower << endl;
}
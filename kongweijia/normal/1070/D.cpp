#include <bits/stdc++.h>
using namespace std;

#define sc scanf
#define pr printf

typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;
    ll res = 0;
    bool flag = false;
    int rem = 0, a, add;
    while (n--) {
        cin >> a;
        a += rem;
        if (a < k) {
            if (flag) {
                ++res;
                flag = false;
                rem = 0;
            }
            else {
                flag = rem = a;
            }
        }
        else {
            res += a / k;
            rem = a % k;
            flag = rem;
        }
    }
    flag ? ++res : 0;
    cout << res << endl;
    return 0;
}
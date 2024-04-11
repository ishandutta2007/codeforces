#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    cout.precision(10);
    long double n, r;
    cin >> n >> r;
    long double ok = 100000000;
    long double ng = 0;
    for(int i = 0; i < 10000; i++) {
        long double mid = (ok + ng) / 2;
        if((mid + r) * sin(PI / n) <= mid) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << ok << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    int n;
    cin >> n;
    for(int time = 1; time <= n; time++) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int ans1 = l1;
        int ans2 = l2;
        if(l1 == l2) ans2++;
        cout << ans1 << " " << ans2 << endl;
    }
    return 0;
}
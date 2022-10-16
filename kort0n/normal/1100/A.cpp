#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    int n, k;
    cin >> n >> k;
    int ans = 0;
    int a[105];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int b = 0; b < k; b++) {
        int e = 0;
        int s = 0;
        for(int i = 1; i <= n; i++) {
            if((i - b) % k == 0) continue;
            if(a[i] == 1) e++;
            else s++;
        }
        ans = max(ans, abs(e - s));
    }
    cout << ans << endl;
    return 0;
}
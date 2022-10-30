#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
using namespace std;
typedef long long LL;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
inline bool valid(int x, int w) { return 0 <= x && x < w; }

void iostream_init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
}

int main(){
    iostream_init();
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    for (int i = 3; i <= c; i++) {
        if(i - 2 <= a && i - 1 <= b && i <= c) {
            ans = i - 2 + i - 1 + i;
        }
    }
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    long long n;
    int q;
    cin >> n >> q;
    for(int i = 0; i < q; i++){
        long long x, y;
        cin >> x >> y;
        swap(x, y);
        long long ans = 0;
        if(((x + y) % 2) == 1){
            ans += (n * n + 1) / 2;
        }
        ans += n * ((y - 1) / 2);
        y = ((y - 1) % 2) + 1;
        if(y == 2){
            if((x + y) % 2 == 1){
                ans += n / 2;
            } else {
            ans += (n + 1) / 2;
            }
        }
        ans += (x + 1) / 2;
        cout << ans << endl;
    }
    return 0;
}
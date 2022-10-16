#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    int d, n;
    cin >> n >> d;
    int m;
    cin >> m;
    for(int time = 1; time <= m; time++){
        int x, y;
        cin >> x >> y;
        if((x + y) < d){
            cout << "NO" << endl;
            continue;
        }
        if((x + y) > (2 * n - d)){
            cout << "NO" << endl;
            continue;
        }
        if((y - x) > d){
            cout << "NO" << endl;
            continue;
        }
        if((x - y) > d){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
    return 0;
}
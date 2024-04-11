#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    int t;
    cin >> t;
    for(int time = 0; time < t; time++){
        int ang;
        cin >> ang;
        if(ang == 180){
            cout << -1 << endl;
            continue;
        }
        ang *= 2;
        int b = 1;
        int a;
        while(true){
            if((360 * b % ang) != 0){
                b++;
                continue;
            }
            a = 360 * b / ang;
            //cout << ang << " " << b << " " << a << endl;
            if(b + 1 < a) break;
            b++;
        }
        int ans = 360 * b / ang;
        //if(ang >= 180) ans = ans * 2;
        cout << ans << endl;
    }
    return 0;
}
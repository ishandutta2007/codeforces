#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

int main() {
    cout.precision(100);
    long double ok = 1000000000000000000;
    long double ng = 0;
    long double epsilon = 0.000001;
    int n;
    cin >> n;
    long double x[100200];
    long double y[100200];
    for(int i = 1; i <= n; i++){
        cin >>x[i] >> y[i];
    }
    for(int i = 2; i <= n; i++){
        if(y[i - 1] * y[i] < 0){
            cout << -1 << endl;
            return 0;
        }
    }
    long double ymaxi = 0;
    for(int i = 1; i <= n; i++){
        y[i] = max(y[i], -y[i]);
        ymaxi = max(ymaxi, y[i]);
    }
    for(int time = 0; time < 500; time++){
        //cout << ng << " " << ok << endl;
        long double mid = (ok + ng) / 2;
        if(ymaxi > (2 * mid)){
            ng = mid;
            continue;
        }
        bool checker = true;
        long double mini = -2000000000000000000;
        long double maxi = 2000000000000000000;
        for(int i = 1; i <= n; i++){
            long double Y = y[i];
            long double X = x[i];
            if(Y > mid){
                Y = 2 * mid - Y;
            }
            long double dx = sqrt(2 * mid * Y - Y * Y);
            if(maxi < (X - dx)){
                checker = false;
            }
            if(mini > (X + dx)){
                checker = false;
            }
            maxi = min(maxi, dx + X);
            mini = max(mini, X - dx);
        }
        if(checker){
            ok = mid;
            //cout << "ok " << mid << endl;
            continue;
        }
        //cout << "ng " << mid << endl;
        ng = mid;
    }
    cout << ok << endl;
    return 0;
}
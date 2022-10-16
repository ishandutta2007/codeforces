#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int a[100100];
int dp1[5010][2510];//
int dp2[5010][2510];//1
int dp3[5010][2510];//1

int main() {
    //cout.precision(10);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }
    if(n == 2){
        if(a[1] != a[2]){
            cout << 0 << endl;
            return 0;
        } else {
            cout << 1 << endl;
            return 0;
        }
    }
    a[n + 1] = -INF;
    for(int i = 0; i <= 5005; i++){
        dp1[i][0] = INF;
        dp2[i][0] = INF;
        dp3[i][0] = 0;
        for(int j = 1; j <= 2505; j++){
            dp1[i][j] = INF;
            dp2[i][j] = INF;
            dp3[i][j] = INF;
        }
    }
    dp1[1][1] = max(0, a[2] - a[1] + 1);
    dp2[1][1] = INF;
    dp3[1][1] = INF;
    dp1[2][1] = max(0, a[1] - a[2] + 1) + max(0, a[3] - a[2] + 1);
    dp2[2][1] = dp1[1][1];
    dp3[2][1] = INF;
    for(int i = 3; i <= n; i++){
        for(int j = 1; j <= (i + 1) / 2; j++){
            /*if(a[i] >= a[i - 2]){
                dp1[i][j] = min(dp2[i - 1][j - 1] + max(0, a[i + 1] - a[i] + 1), dp1[i][j]);
            } else {
                dp1[i][j] = min(dp1[i][j], dp2[i - 1][j - 1] + (a[i - 2] - 1 - a[i] + 1) + max(0, a[i + 1] - a[i] + 1));
            }*/
            if(a[i - 1] >= a[i - 2]){
                dp1[i][j] = min(dp1[i][j], dp2[i - 1][j - 1] + max(0, a[i - 2] - 1 - a[i] + 1) + max(0, a[i + 1] - a[i] + 1));
            } else {
                dp1[i][j] = min(dp1[i][j], dp2[i - 1][j - 1] + max(0, a[i - 1] - a[i] + 1) + max(0, a[i + 1] - a[i] + 1));
            }
            dp1[i][j] = min(dp1[i][j], dp3[i - 1][j - 1] + max(0, a[i + 1] - a[i] + 1) + max(0, a[i - 1] - a[i] + 1));
            dp2[i][j] = dp1[i - 1][j];
            dp3[i][j] = min(dp2[i - 1][j], dp3[i - 1][j]);
        }
    }
    /*for(int i = 1; i <= n; i++){
        for(int j = 0; j <= n / 2 + 1; j++){
            cout << i << " " << j << " " << dp1[i][j] << " " << dp2[i][j] << " " << dp3[i][j] << endl;
        }
    }*/
    for(int i = 1; i <= (n + 1) / 2; i++){
        cout << min(min(dp1[n][i], dp2[n][i]), dp3[n][i]) << " ";
    }
    cout << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

//random_device rd;
//uniform_int_distribution<int> nn(2, 300);
//uniform_int_distribution<int> dist(0, 1000000000);
//      chrono::system_clock::now();
//      chrono::duration_cast<chrono::milliseconds>(finish - start).count()

const ld eps = 1e-10;

int dp[100002][3];
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    vector<int> x, h;
    cin >> n;
    int a, b;
    for(int i = 0; i < n; ++i){
        cin >> a >> b;
        x.push_back(a);
        h.push_back(b);
    }
    dp[0][0] = 0;
    dp[0][1] = 1;
    if(n == 1 || x[1] > x[0] + h[0]){
        dp[0][2] = 1;
    }else{
        dp[0][2] = 0;
    }
    for(int i = 1; i < n; ++i){
        dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
        dp[i][1] = -1;
        if(x[i - 1] < x[i] - h[i]){
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
            if(x[i - 1] + h[i - 1] < x[i] - h[i]){
                dp[i][1] = max(dp[i][1], dp[i - 1][2]);
            }
            dp[i][1]++;
        }
        dp[i][2] = -1;
        if(i + 1 == n || x[i + 1] > x[i] + h[i]){
            dp[i][2] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2])) + 1;
        }
    }
    cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2])) << endl;


}
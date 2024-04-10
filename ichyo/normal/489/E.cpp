#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int n, l;
int p[1010];
int b[1010];
bool check(double x) {
    double dp[1010] = {};
    REP(i, n) dp[i] = -1e16;
    dp[0] = 0;

    for(int j = 1; j < n; j++) {
        for(int i = 0; i < j; i++) {
            double f = sqrt(abs((p[j] - p[i]) - l));
            dp[j] = max(dp[j], dp[i] + (x * b[j] - f));
        }
    }

    return (dp[n-1] >= 0);
}

vector<int> calc(double x) {
    double dp[1010] = {};
    int back[1010] = {};
    REP(i, n) dp[i] = -1e16;
    dp[0] = 0;

    for(int j = 1; j < n; j++) {
        for(int i = 0; i < j; i++) {
            double f = sqrt(abs((p[j] - p[i]) - l));
            if(dp[j] < dp[i] + (x * b[j] - f)) {
                dp[j] = dp[i] + (x * b[j] - f);
                back[j] = i;
            }
        }
    }

    vector<int> res;
    int idx = n - 1;
    while(idx > 0) {
        res.push_back(idx);
        idx = back[idx];
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    cin >> n >> l;
    n++;
    for(int i = 1; i < n; i++) {
        cin >> p[i] >> b[i];
    }

    double lb = 0, ub = 1000;
    REP(_, 80) {
        double x = (lb + ub) / 2;
        if(check(x)) {
            ub = x;
        } else {
            lb = x;
        }
    }
    
    //printf("%f %f\n", lb, ub);

    auto v = calc(ub);
    for(int i = 0; i < v.size(); i++) {
        cout << v[i];
        if(i == v.size() - 1) {
            cout << endl;
        } else {
            cout << " ";
        }
    }

    return 0;
}
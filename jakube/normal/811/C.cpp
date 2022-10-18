#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
vector<int> most_right(5001, -1);
vector<int> most_left(5001, 999999);
vector<int> dp;

int f(int i) {
    int upto = i;
    vector<bool> visited(5001, false);
    int xori = 0;
    for (int j = i; j <= upto; j++) {
        if (!visited[v[j]])
            xori ^= v[j];
        visited[v[j]] = true;
        if (most_left[v[j]] < i)
           return dp[i] = dp[i+1]; 
        upto = max(upto, most_right[v[j]]);
    }

    return dp[i] = max(dp[i + 1], xori + dp[upto + 1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    dp.assign(n+1, 0);

    for (int i = 0; i < n; i++) {
        most_right[v[i]] = i;
    }
    for (int i = n - 1; i >= 0; i--) {
        most_left[v[i]] = i;
    }
    
    int result = 0;
    for (int i = n-1; i >= 0; i--) {
        result = max(result, f(i));
    }
    

    cout << result << endl;
}
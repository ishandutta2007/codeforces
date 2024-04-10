#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

vector<int> x, y, s;
int n, a, b;

bool possible(int i, int j){
    if(max(x[i], x[j]) <= a && y[i] + y[j] <= b){
        return true;
    }
    if(max(x[i], x[j]) <= b && y[i] + y[j] <= a){
        return true;
    }
    if(max(x[i], y[j]) <= a && y[i] + x[j] <= b){
        return true;
    }
    if(max(x[i], y[j]) <= b && y[i] + x[j] <= a){
        return true;
    }
    if(max(y[i], x[j]) <= a && x[i] + y[j] <= b){
        return true;
    }
    if(max(y[i], x[j]) <= b && x[i] + y[j] <= a){
        return true;
    }
    if(max(y[i], y[j]) <= a && x[i] + x[j] <= b){
        return true;
    }
    if(max(y[i], y[j]) <= b && x[i] + x[j] <= a){
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> a >> b;
    x.resize(n);
    y.resize(n);
    s.resize(n);
    for(int i = 0; i < n; ++i){
        cin >> x[i] >> y[i];
        if(x[i] < y[i]){
            swap(x[i], y[i]);
        }
        s[i] = x[i] * y[i];
    }
    int ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            if(possible(i, j)){
                ans = max(ans, s[i] + s[j]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
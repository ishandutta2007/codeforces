#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int x[N], y[N];
int main(){
    int a, b, n;
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i++){ cin >> x[i] >> y[i];}
        int ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++){
            swap(x[i], y[i]);

            if(x[i] + x[j] <= a && max(y[i], y[j]) <= b) ans = max(ans, x[i] * y[i] + x[j] * y[j]);
            if(y[i] + y[j] <= b && max(x[i], x[j]) <= a) ans = max(ans, x[i] * y[i] + x[j] * y[j]);

            swap(x[j], y[j]);

            if(x[i] + x[j] <= a && max(y[i], y[j]) <= b) ans = max(ans, x[i] * y[i] + x[j] * y[j]);
            if(y[i] + y[j] <= b && max(x[i], x[j]) <= a) ans = max(ans, x[i] * y[i] + x[j] * y[j]);

            swap(x[i], y[i]);

            if(x[i] + x[j] <= a && max(y[i], y[j]) <= b) ans = max(ans, x[i] * y[i] + x[j] * y[j]);
            if(y[i] + y[j] <= b && max(x[i], x[j]) <= a) ans = max(ans, x[i] * y[i] + x[j] * y[j]);

            swap(x[j], y[j]);

            if(x[i] + x[j] <= a && max(y[i], y[j]) <= b) ans = max(ans, x[i] * y[i] + x[j] * y[j]);
            if(y[i] + y[j] <= b && max(x[i], x[j]) <= a) ans = max(ans, x[i] * y[i] + x[j] * y[j]);
        }
    cout << ans;
}
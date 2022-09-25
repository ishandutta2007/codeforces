#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 10000;
int a[maxn + 1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, sum = 0;
        cin >> n;
        for(int i = 1; i <= n; i += 1){
            cin >> a[i];
            sum += a[i];
        }
        if(sum % n){
            cout << "-1\n";
            continue;
        }
        cout << 3 * n - 3 << "\n";
        for(int i = 2; i <= n; i += 1){
            int x = a[i] % i ? i - a[i] % i : 0;
            cout << 1 << " " << i << " " << x << "\n";
            a[1] -= x;
            a[i] += x;
            x = a[i] / i;
            cout << i << " " << 1 << " " << x << "\n";
            a[1] += x * i;
            a[i] -= x * i;
        }
        for(int i = 2; i <= n; i += 1){
            int x = sum / n;
            cout << 1 << " " << i << " " << x << "\n";
            a[1] -= x;
            a[i] += x;
        }
        for(int i = 1; i <= n; i += 1) assert(a[i] == a[1]);
    }
    return 0;
}
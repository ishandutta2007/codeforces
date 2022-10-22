#include <bits/stdc++.h>
using namespace std;

long long n, a[101];

int p(int k, long long x){
    int r = 0;
    while(x % k == 0) r ++, x /= k;
    return r;
}

signed main(){
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, [](long long &x, long long &y){
        return p(2, x) < p(2, y) || (p(2, x) == p(2, y) && p(3, x) > p(3, y));
    });
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
}
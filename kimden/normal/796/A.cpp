#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int a[1000];

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    int ans = 99999;
    m--;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        if(i != m && a[i] != 0 && a[i] <= k){
            ans = min(ans, abs(i - m));
        }
    }
    cout << (ans * 10) << endl;
}
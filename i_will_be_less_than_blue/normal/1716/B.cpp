#include <bits/stdc++.h>

int a[105];

using namespace std;
void solve(){
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) a[i] = i + 1;
    cout << n << '\n';
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < n; ++j) cout << a[j] << ' ';
        cout << '\n';
        swap(a[i], a[i - 1]);
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
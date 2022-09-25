#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100;
int a[maxn], b[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        for(int i = 0; i < n; i += 1) cin >> a[i];
        for(int i = 0; i < n; i += 1) cin >> b[i];
        sort(a, a + n);
        sort(b, b + n);
        for(int i = 0; i < n; i += 1) cout << a[i] << " ";
        cout << "\n";
        for(int i = 0; i < n; i += 1) cout << b[i] << " ";
        cout << "\n";
    }
    return 0;
}
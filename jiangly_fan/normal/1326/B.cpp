#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = -1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int x = 0;
    for(int i = 0, b; i < n; i += 1){
        cin >> b;
        cout << x + b << " ";
        x = max(x, x + b);
    }
    return 0;
}
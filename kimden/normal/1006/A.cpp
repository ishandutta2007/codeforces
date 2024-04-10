#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int x;
    for(int i = 0; i < n; ++i){
        cin >> x;
        if(x % 2 == 0){
            --x;
        }
        if(i){
            cout << " ";
        }
        cout << x;
    }
    cout << endl;
    return 0;
}
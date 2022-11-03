#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;




int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    ll sum = 0;
    int a[1000];
    int idx = -1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        if(idx == -1 && sum != 0){
            idx = i;
        }
    }
    if(sum != 0){
        cout << "YES" << endl << "1" << endl << "1 " << n << endl;
    }else{
        if(idx == -1) {
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl << "2" << endl << "1 " << idx + 1 << endl << idx + 2 << " " << n << endl;
        }
    }
    return 0;
}
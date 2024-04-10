#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        vector<int> a(N), b(N);
        for (int i = 0; i < N; ++i){
            cin >> a[i];
        }
        for (int i = 0; i < N; ++i){
            cin >> b[i];
        }
        vector<int> d(N);
        for (int i = 0; i < N; ++i){
            if (i > 0 && a[i] < b[i-1]){
                a[i] = b[i-1];
            }
            cout << b[i] - a[i] << " ";
        }
        cout << '\n';
    }
}
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N, X, Y; cin >> N >> X >> Y;
        if (Y > X) swap(X, Y);
        if (Y != 0) cout << -1 << '\n';
        else{
            if (X == 0 || (N - 1) % X) cout << -1 << '\n';
            else{
                for (int i = 0; i < N-1; ++i){
                    cout << (i / X) * X + 2 << " ";
                }
                cout << '\n';
            }
        }
    }
}
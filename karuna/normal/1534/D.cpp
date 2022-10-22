#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;
const int M = 2e3 + 10;

int n, A[M], C[M];
vector<pint> Ans;

int main() {
    cin >> n;

    cout << "? 1" << endl;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    int c = 0;
    for (int i = 1; i <= n; i++) {
        if (A[i] & 1) --c;
        else ++c;
    }
    vector<int> V; 
    if (c > 0) {
        for (int i = 1; i <= n; i++) if (A[i] & 1) {
            V.push_back(i);
        }
    }
    else {
        for (int i = 1; i <= n; i++) {
            if (A[i] == 1) Ans.emplace_back(1, i);
            if (~A[i] & 1) if (i != 1) V.push_back(i);
        }
    }
    while (!V.empty()) {
        int x = V.back(); V.pop_back();
        cout << "? "  << x << endl;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }
        for (int i = 1; i <= n; i++) {
            if (A[i] == 1) Ans.emplace_back(x, i);
        }
    }   
    cout << "!\n";
    for (auto [x, y] : Ans) {
        cout << x << ' ' << y << endl;
    }
}
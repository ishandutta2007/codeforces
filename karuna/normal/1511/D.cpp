#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;
typedef pair<lint, lint> plint;
const int MAX = 1e5 + 10;

int n, k;
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> k; 
    string S = "a";
    for (int i = 0; i < k; i++) {
        for (int j = k - 1; j > i; j--) {
            S += (char)('a' + i);
            S += (char)('a' + j);
        }
    }
    for (int j = k - 1; j > 0; j--) S += (char)('a' + j);
    if (n < (int)S.size()) cout << S.substr(0, n);
    else {
        string T = "";
        for (int i = 0; i < n / (int)S.size(); i++) T += S;
        cout << T + S.substr(0, n % (int)S.size());
    }
}
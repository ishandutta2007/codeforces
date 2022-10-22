#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;
typedef pair<lint, lint> plint;
const int MAX = 1e5 + 10;

int n, x; string S;
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        cin >> n >> S; x = 0;
        for (int i = 1; i < n - 1; i++) x += (S[i] == '1');
        if (S[0] == '0' || S[n - 1] == '0' || (x & 1)) {
            cout << "NO\n"; continue;
        }
        int c = 0, d = 0;
        string A = "(", B = "(";
        for (int i = 1; i < n - 1; i++) {
            if (S[i] == '0') {
                if (!(c & 1)) A += "(", B += ")";
                else A += ")", B += "("; ++c;
            }
            else {
                if (!(d & 1)) A += "(", B += "(";
                else A += ")", B += ")"; ++d;
            }
        }
        cout << "YES\n" << A << ")\n" << B << ")\n";
    }
}
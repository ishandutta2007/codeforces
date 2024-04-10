#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int t, n, k;
int main() {
    cin >> t;
    while (t--) {
        cin >> n >> k;

        if (k%3==1 || k%3==2) {
            if (n%3==0) cout << "Bob" << '\n';
            else cout << "Alice" << '\n';
        }
        else {
            if ((n%(k+1))%3==0 && n%(k+1) != k) cout << "Bob" << '\n';
            else cout << "Alice" << '\n';
        }
    }
}
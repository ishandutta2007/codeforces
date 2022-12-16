#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int a[k];
        for (int i = 0; i < k; i++) {
            char c;
            cin >> c;
            a[i] = c - '0';
        }

        bool found = false;

        for (int i = 0; i < k; i++) {
            if (primes.count(a[i]) == 0) {
                cout << 1 << endl;
                cout << a[i] << endl;
                found = true;
                break;
            }
        }
        if (found) continue;

        for (int i = 0; i < k; i++) {
            for (int j = i+1; j < k; j++) {
                int num = 10*a[i] + a[j];
                if (primes.count(num) == 0) {
                    cout << 2 << endl;
                    cout << num << endl;
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
    }
}
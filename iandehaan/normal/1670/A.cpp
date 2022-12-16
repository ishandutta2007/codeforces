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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        int numneg = 0;
        rep(i, 0, n) {
            cin >> a[i];
            if (a[i] < 0) {
                numneg++;
                a[i] *= -1;
            }
        }
        rep(i, 0, numneg) {
            a[i] *= -1;
        }
        string out = "YES";
        rep(i, 0, n-1) {
            if (a[i] > a[i+1]) out = "NO";
        }
        cout << out << endl;
    }
}
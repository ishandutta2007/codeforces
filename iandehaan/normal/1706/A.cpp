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
        int n, m;
        cin >> n >> m;
        string b;
        rep(i, 0, m) b.pb('B');
        rep(i, 0, n) {
            int x;
            cin >> x;
            int ind1 = x-1;
            int ind2 = m-x;
            int x1 = min(ind1, ind2);
            int x2 = max(ind1, ind2);
            if (b[x1] == 'B') b[x1] = 'A';
            else b[x2] = 'A';
        }
        cout << b << endl;
    }
}
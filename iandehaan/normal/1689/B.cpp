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
        priority_queue<int, vector<int>, greater<int>> avail;
        rep(i, 1, n+1) avail.push(i);

        int a[n];
        rep(i, 0, n) cin >> a[i];

        if (n == 1) {
            cout << -1 << endl;
            continue;
        }

        rep(i, 0, n-2) {
            if (avail.top() == a[i]) {
                int nonuse = avail.top();
                avail.pop();
                cout << avail.top() << ' ';
                avail.pop();
                avail.push(nonuse);
            } else {
                cout << avail.top() << ' ';
                avail.pop();
            }
        }
        int rem1 = avail.top(); avail.pop();
        int rem2 = avail.top(); avail.pop();
        if (rem1 == a[n-2] || rem2 == a[n-1]) {
            cout << rem2 << ' ' << rem1 << endl;
        } else {
            cout << rem1 << ' ' << rem2 << endl;
        }
    }
}
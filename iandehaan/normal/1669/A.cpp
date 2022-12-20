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
        int r;
        cin >> r;
        cout << "Division ";
        if (r <= 1399) cout << 4;
        else if (r <= 1599) cout << 3;
        else if (r <= 1899) cout << 2;
        else cout << 1;
        cout << endl;
    }
}